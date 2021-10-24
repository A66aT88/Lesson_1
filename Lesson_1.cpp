#include <iostream>
#include <cstdint>

/* Задание 1
* Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, 
* изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения.
* Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов.
* В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
*/

int studentsCount = 0;

class Person {
	std::string name;
	std::string gender;
	int age;
	int veight;

public:
	// Можно было засунуть геттеры и сеттеры в protected, но я посчитал, что нам может потребоваться в любой момент любая информация о студенте 
	// в отрыве от остальных данных. Например, только имя и возраст или только пол (если захотим посчитать % парней и девушек)
	// так что удобнее сделать геттеры и сеттеры в публичном поле

	void setName(std::string newName) { name = newName;	}
	void setAge(int newAge) { age = newAge; }
	void setVeight(int newVeight) { veight = newVeight; }

	std::string getName() { return name; }
	std::string getGender() { return gender; }
	int getAge() { return age; }
	int getVeight() { return veight; }

	Person(std::string newName, std::string newGender, int newAge, int newVeight) : name(newName), gender(newGender), age(newAge), veight(newVeight){ }
};

class Student : public Person {
	int studyYear;

public:
	Student(std::string name, std::string gender, int age, int veight, int newStudyYear) : Person(name, gender, age, veight) {
		studyYear = newStudyYear;
		studentsCount++;
	}

	~Student() {
		studentsCount--;
	}

	void setStudyYear(int newStudyYear) { studyYear = newStudyYear; }
	int getStudyYear() { return studyYear; }
	void getStudentData();
};

void Student::getStudentData() {
	std::cout << "Name: " << this->getName() << std::endl << "Gender: " << this->getGender() << std::endl << "Age: " << this->getAge() << std::endl << "Veight: " << this->getVeight() << std::endl << "Study year: " << this->getStudyYear() << std::endl;
};

/* Задание 2
* Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
* У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.
*/

class Fruit {
	std::string name;
	std::string color;

protected:
	void setName(std::string newName) { name = newName;	}
	void setColor(std::string newColor) { color = newColor; }

public:

	Fruit(std::string newName, std::string newColor) : name(newName), color(newColor){ }
	std::string getName() { return name; }
	std::string getColor() { return color; }
};

class Apple : public Fruit {
public:
	Apple(std::string color = "green") : Fruit("apple", color) {}
	Apple(std::string name, std::string color) : Fruit(name, color) {}
};

class Banana : public Fruit {
public:
	Banana(std::string color = "yellow") : Fruit("banana", color) {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("Granny Smith apple", "green") {}
};

int main()
{
	// Задание 1
	
	Student s0("John Doe", "Male", 22, 85, 4);
	std::cout << "Student 0: " << std::endl;
	s0.getStudentData();

	std::cout << std::endl << "Students count: " << studentsCount << std::endl << std::endl;

	Student s1("Jane Doe", "Female", 21, 55, 2);
	Student s2("Steve Rogers", "Male", 23, 88, 4);

	std::cout << "Student 1: " << std::endl;
	s1.getStudentData();
	std::cout << std::endl;
	std::cout << "Student 2: " << std::endl;
	s2.getStudentData();
	std::cout << std::endl << "Students count: " << studentsCount << std::endl << std::endl;

	// Задание 2

	Apple a0("red");
	Banana b0;
	GrannySmith c0;

	std::cout << "My " << a0.getName() << " is " << a0.getColor() << ".\n";
	std::cout << "My " << b0.getName() << " is " << b0.getColor() << ".\n";
	std::cout << "My " << c0.getName() << " is " << c0.getColor() << ".\n";

	/* Задание 3
	* Создаем класс Player. У него будет три свойства
	* int cards - число карт на руках
	* int sum - сумма очков
	* int deal - текущая ставка
	* 
	* И методы 
	* getCard() - добавляет карту и пересчитывает сумму очков
	* 1to1() - в сулчае если у дилера первая карта 10 или туз
	* hold() - оставить текущее число карт 
	*/

	return 0;
}

