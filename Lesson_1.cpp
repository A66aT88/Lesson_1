#include <iostream>
#include <cassert>
#include <vector>

#include "Hand.h"

/* Задание 1
* Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
*/

template <class myType>
class Pair1 {
	myType firstVal;
	myType secondVal;
public:
	Pair1(myType a, myType b) : firstVal(a), secondVal(b) {}
	virtual ~Pair1() {}
	myType first() {
		return firstVal;
	}
	myType second() {
		return secondVal;
	}
};

/* Задание 2
* Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
*/

template <class firstType, class secondType>
class Pair {
	firstType firstVal;
	secondType secondVal;
public:
	Pair(firstType a, secondType b) : firstVal(a), secondVal(b) {}
	virtual ~Pair() {}
	firstType first() {
		return firstVal;
	}
	secondType second() {
		return secondVal;
	}
};

/* Задание 3
* Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. 
* Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string,
* а второй — любого типа данных.
*/

// Назвал Pair2, т.к. Pair уже есть
template <char* StringType, class SecondType> 
class Pair2 { };

// Судя по методичке и по описанию задания, тут мы просто копируем параметры шаблона (имею ввиду принимаемы типа данных) родительского класса
template <char* StringType, class SecondType>
class StringValuePair : public Pair2<StringType, SecondType> {};

// Не совсем понял, почему не могу использовать в качестве второго типа данных int
// Получаю тут ошибку компилятора
// constant data не используется или не может быть выведено из списка аргументов шаблона шаблон класса
//template <char* StringType, int data>
//class StringValuePair<StringType, data> : public Pair2<StringType, data> {};


/* Задание 4
* Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
* который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer,
* в который добавить поле name - имя игрока. Также добавить 3 метода:
* IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
* IsBoosted() - возвращает bool значение, есть ли у игрока перебор
* Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/

class GenericPlayer : public Hand {
	std::string name;
public:
	GenericPlayer(std::string newName) : Hand(), name(newName) {}
	virtual void isHitting() = 0;
	bool isBoosted() {
		(this->GetValue() > 21) ? false : true;
	}
	void Bust() {
		std::cout << "Players name: " << name << ". Status: Bust" << std::endl;
	}
};

int main()
{
	// Задание 1
	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	// const Pair1<double> p2(3.4, 7.8); - вот эта строка как в методичке вызывает ошибку компилятора
	// myType Pair1<myType>::first(void): невозможно преобразовать указатель "this" из "const Pair1<double>" в "Pair1<double> &"
	// Не совсем понимаю, в чем проблема. this указывает на текущий класс, т.е. нам надо делать класс константным, чтобы тут работала строка из методички ?
	// Вот так все работает:
	Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	// Задание 2
	Pair<int, double> p3(6, 7.8);
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	Pair<double, int> p4(3.4, 5);
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	return 0;
}

