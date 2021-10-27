#include <iostream>
#include <cstdint>
#include <cassert>

/* Задание 1
* Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
* Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
* Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
* Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/

class Figure {
public:
	Figure() {}
	virtual int area() = 0;
};

class Parallelogram : public Figure {
	int sideA;
	int sideB; // длина высоты проведенной к вершине стороны А
public:
	Parallelogram(int newSideA, int newSideB) : sideA(newSideA), sideB(newSideB) { };

	virtual ~Parallelogram() {};

	int getSideA() { return sideA; }
	int getSideB() { return sideB; }
	int area() override {
		return sideA * sideB;
	}
};

class Circle : public Figure {
	double radius;
public:
	Circle(int r) : radius(r) {}
	int area() override {
		//Если Вы не против, я тут не буду подключать математические либы, это же все-таки задача не по математике, а по ООП :) ограничусь схематическим видом числа Пи
		return 3.14 * radius * radius;
	}
	int getRadius() { return radius; }
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int newSideA, int newSideB) : Parallelogram(newSideA, newSideB) { };

	int area() override {
		return this->getSideA() * this->getSideB();
	}
};

class Square : public Parallelogram {
public:
	Square(int newSideA, int newSideB = 0) : Parallelogram(newSideA, newSideA) { };

	int area() override {
		return this->getSideA() * this->getSideA();
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int newSideA, int newSideB) : Parallelogram(newSideA, newSideB) { };
	// расчет ведем через сторону и высоту к данной стороне ромба
	int area() override {
		return this->getSideA() * this->getSideB();
	}
};

/* Задание 2
* Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники:
* PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн).
* Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для
* каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
*/

class Car {
	std::string name;
	std::string model;
public:
	Car(std::string newName, std::string newModel) : name(newName), model(newModel) {
		std::cout << "Car constructor" << std::endl;
	}

	virtual ~Car() {}
};

class PassengerCar : virtual public Car{
public:
	PassengerCar(std::string newName, std::string newModel) : Car(newName, newModel) {
		std::cout << "PassengerCar constructor" << std::endl;
	}

};

class Bus : virtual public Car{
public:
	Bus(std::string newName, std::string newModel) : Car(newName, newModel) {
		std::cout << "Bus constructor" << std::endl;
	}

};

class Minivan : public PassengerCar, public Bus {
public:
	// Если не делать виртуадльное наследование у классов PassengerCar и Bus, то класс Car создастся два раза, для каждого из родительских классов
	// Minivan(std::string newName, std::string newModel) : PassengerCar(newName, newModel), Bus(newName, newModel) {
	Minivan(std::string newName, std::string newModel) : PassengerCar(newName, newModel), Bus(newName, newModel) , Car(newName, newModel) { 		
		std::cout << "Minivan constructor" << std::endl;
	}

};

/* Задание 3
* Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
* математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
* унарный оператор (-)
* логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
*/

class Fraction {
	int num;
	int divider;
public:
	Fraction(int newNum, int newDivider = 1) {
		// Проверку нагуглил :(
		assert(newDivider != 0);
		num = newNum;
		divider = newDivider;
	}
	int getNum() { return num; }
	int getDivider() { return divider; }

	friend Fraction operator+(const Fraction& l, const Fraction& r);
	friend Fraction operator/(const Fraction& l, const Fraction& r);
	friend bool operator>(const Fraction& l, const Fraction& r);
};

Fraction operator+(const Fraction& l, const Fraction& r) {
	if (l.divider == r.divider) {
		return Fraction(l.num + r.num, r.divider);
	}
	else {
		if ((l.divider % r.divider) == 0) 
		{
			return Fraction((l.num * (l.divider / r.divider)) + r.num, l.divider);
		}
		else if ((r.divider % l.divider) == 0)
		{
			return Fraction(l.num + (r.num * (r.divider / l.divider)), r.divider);
		}
		else {
			return Fraction((l.num * r.divider) + (r.num * l.divider), l.divider * r.divider);
		}		
	}
};

Fraction operator/(const Fraction& l, const Fraction& r) {
	return Fraction((l.num * r.divider), (r.num * l.divider));
};

bool operator>(const Fraction& l, const Fraction& r) {
	bool res;
	if (l.divider == r.divider) {
		res = (l.num > r.num) ? true : false;
	}
	else {
		res = ((l.num * r.divider) > (r.num * l.divider)) ? true : false;
	}

	return res;
};

/* Задание 4
* Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
* Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода: 
* метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
* метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

enum cardSuit {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

enum cardValue {
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	ACE = 1
};

class Card {
	cardSuit suit;
	cardValue value;
	bool cardPos;
public:
	Card(cardSuit newSuit, cardValue newValue, bool newPos) : suit(newSuit), value(newValue), cardPos(newPos) {}
	virtual ~Card() {}

	cardSuit getSuit() { return suit; }
	cardValue getValue() { return value; }
	bool getPos() { return cardPos; }

	void flip() {
		cardPos = !cardPos;
	}
};

int main()
{
	// Задание 1
	Rectangle rec1(4, 6);
	Rhombus rh1(5, 8);
	Circle cr1(7);
	std::cout << "Rectangle square: " << rec1.getSideA() << " * " << rec1.getSideB() << " = " << rec1.area() << std::endl;
	std::cout << "Rhombus square: " << rh1.getSideA() << " * " << rh1.getSideB() << " = " << rh1.area() << std::endl;
	std::cout << "Circle square: " << cr1.getRadius() << " = " << cr1.area() << std::endl;

	// Задание 2
	Minivan mini0("Hiace", "Toyota");

	// Задание 3

	Fraction f0(2, 3);
	Fraction f1(3, 5);
	std::cout << "Fractions : " << f0.getNum() << "/" << f0.getDivider() << ", " << f1.getNum() << "/" << f1.getDivider() << std::endl;
	Fraction fRes = f0 + f1;
	std::cout << "Result summ: " << fRes.getNum() << "/" << fRes.getDivider() << std::endl;
	fRes = f0 / f1;
	std::cout << "Result divide: " << fRes.getNum() << "/" << fRes.getDivider() << std::endl;
	bool compare;
	compare = f0 > f1;
	std::cout << "Result compare: " << ((compare) ? "Left is bigger" : "Right is bigger") << std::endl;

	// Задание 4
	Card c0(HEARTS, JACK, true);
	std::cout << "Card value: " << c0.getValue() << std::endl;
	std::cout << "Card position: " << ((c0.getPos()) ? "Suite down" : "Suite up") << std::endl;
	c0.flip();
	std::cout << "Card position: " << ((c0.getPos()) ? "Suite down" : "Suite up") << std::endl;

	return 0;
}

