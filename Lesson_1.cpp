#include <iostream>
#include <string>
#include <vector>

#include "GenericPlayer.h"

/* Задание 1
* Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
* если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и
* предложить ввести число еще раз. Пример неправильных введенных строк:
*
* rbtrb
* nj34njkn
* 1n
*/

bool checkDigit(std::string string) {
	bool result = true;
	for (int i = 0; i < string.length(); i++) {
		if (!isdigit(string[i])) { return false; }
	}
	return result;
}

/* Задание 2
* Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/
//Вариант 1
class manipulator {
public:
	manipulator() {}

	friend std::ostream& operator<< (std::ostream& out, const manipulator& string);
};

std::ostream& operator<< (std::ostream& out, const manipulator& string)
{
	out << "\n\n";
	out.flush();
	return out;
}
//Вариант 2
std::ostream& endl(std::ostream& stream)
{
	stream << "\n\n";
	stream.flush();
	return stream;
}
//Решил попробовать двумя вариантами, т.к. в методичке не совсем понятно объяснили. Мне показался второй путь красивее, хотя первый как-то ближе к изучаемой теме

/* Задание 3
* Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
* virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя,
* нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false. 
* void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
* void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
* void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

class Player : public GenericPlayer {
public:
	Player(std::string newName) : GenericPlayer(newName) {}
	virtual ~Player() {}
	bool isHitting() override {
		std::string answer;
		std::cout << "Do you need one more card ?\n";
		std::cin >> answer;
		while (answer != "yes" || answer != "Yes" || answer != "+" || answer != "1" || answer != "no" || answer != "No" || answer != "-" || answer != "0") {
			std::cout << "Please, enter your answer Yes or No:\n";
		}
		if (answer == "yes" || answer == "Yes" || answer == "+" || answer == "1") {
			return true;
		}
		else
		{
			return false;
		}
	}
	void Win() const {
		std::cout << "Congratulations !!! You, " << getName() << ", won ! :)";
	}
	void Lose() const {
		std::cout << "So sorry, but, " << getName() << ", you loose at this time :(";
	}
	void Push() const {
		std::cout << "Not so bad. You, " << getName() << "played a draw. Will luck next time.";
	}
};

/* Задание 4
* Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
* virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
* void FlipFirstCard() - метод переворачивает первую карту дилера.
*/

class House : public GenericPlayer {
public:
	House(std::string newName) : GenericPlayer(newName){}
	virtual ~House() {}
	bool isHitting() override {
		if (GetValue() <= 16) {
			// Не совсем понял как реализовать добавление карты дилеру
			//Card c0(HEARTS, JACK, true);
			//this->add(c0);
		}
	}

	void FlipFirstCard() {
		//std::vector<Card*> first = cards.begin();
	}
	
};

/* Задание 5
 * Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), 
 * вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку 
 * оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/

std::ostream& operator<< (std::ostream& out, const Card& card) {
	if (card.getPos()) {
		out << "Card suite: " << card.getSuit() << ". Card value: " << card.getValue();		
	}
	else {
		out << "XX\n";
	}
	return out;
};

std::ostream& operator<< (std::ostream& out, const GenericPlayer& player) {
	out << "Players name: " << player.getName() << "\n";
	for (int i = 0; i < player.cards.size(); i++) {
		out << player.cards[i]->getSuit() << " " << player.cards[i]->getValue() << "\n";
	}
	return out;
};

int main()
{
	
// Задание 1

	std::string inputString;
	std::cout << "Please enter integer number:\n";
	std::cin >> inputString;
	while (!checkDigit(inputString)) {
		std::cout << "Error !\nPlease enter VALID integer number:\n";
		std::cin >> inputString;
	}

//Задание 2
	std::cout << "Test endl 1" << endl;

	manipulator endl;
	std::cout << "Test endl 2" << endl;

	return 0;
}

