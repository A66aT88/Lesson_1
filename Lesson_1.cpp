#include <iostream>
#include <cstdint>

/* Задание 1
* Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена 
* для хранения этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать 
* значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень 
* второго числа. Задать значения этих двух чисел по умолчанию.
*/

class Power {
	int firstVal = 5;
	int secondVal = 10;

public:
	// В задании писалось делать через значения по умолчанию, но мне кажется, через конструктор лучше. 
	// На всякий, код конструктора тут:

	/*Power(int first, int second) {
		this->firstVal = first;
		this->secondVal = second;
	};*/

	void setValues(int first, int second) {
		this->firstVal = first;
		this->secondVal = second;
	};

	int calculate();
};

int Power::calculate() {
	return this->firstVal + this->secondVal;
}

/* Задание 2
* Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: 
* m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0
* в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать
* конструктор со списком инициализации членов, который позволит пользователю передавать значения
* для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов
*/

class RGBA {
	std::uint8_t m_red = 0;
	std::uint8_t m_green = 0;
	std::uint8_t m_blue = 0;
	std::uint8_t m_alpha = 255;
public:

	RGBA(int red, int green, int blue, int alpha) : 
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) { };

	void print();
};

void RGBA::print() {
	std::cout << "Value of m_red: " << this->m_red << std::endl;
	std::cout << "Value of m_green: " << this->m_green << std::endl;
	std::cout << "Value of m_blue: " << this->m_blue << std::endl;
	std::cout << "Value of m_alpha: " << this->m_alpha << std::endl;
};

/* Задание 3
* Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
* private-массив целых чисел длиной 10;
* private целочисленное значение для отслеживания длины стека;
* public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
* public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
* public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
* public-метод с именем print(), который будет выводить все значения стека. 
*/

class Stack {
	int stackMembers[10];
	int cursor = 0;

public:

	Stack() {
		this->stackMembers[10] = {};
		this->cursor = 0;
	};

	void reset();
	bool push(int data);
	int pop();
	void print();
};

void Stack::reset() {
	for (int i = 0; i < this->cursor; i++) {
		this->stackMembers[i] = 0;
	}
	this->cursor = 0;
};

bool Stack::push(int data) {
	if (this->cursor > 9) {
		std::cout << "Stack is full" << std::endl;
		return false;
	}
	else {
		this->stackMembers[this->cursor] = data;
		this->cursor++;
		return true;
	}
};

int Stack::pop() {
	int result;
	if (this->cursor == 0) {
		std::cout << "Empty stack" << std::endl;
		return -1;
	}
	else {
		result = this->stackMembers[this->cursor - 1];
		this->stackMembers[this->cursor - 1] = 0;
		this->cursor--;
		return result;
	}
};

void Stack::print() {
	for (int i = 0; i < this->cursor; i++) {
		std::cout << "Stack member " << i << ": " << this->stackMembers[i] << std::endl;
	}
};



int main()
{
	std::cout << "Task 1: " << std::endl;
	Power p1;
	std::cout << "Calculate: " << p1.calculate() << std::endl;
	std::cout << "Change values to 10, 30 " << std::endl;
	p1.setValues(10, 30);
	std::cout << "New calculate: " << p1.calculate() << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "Task 2: " << std::endl;

	RGBA rgba1(1,6,23,87);
	rgba1.print();

	std::cout << std::endl << std::endl;
	std::cout << "Task 3: " << std::endl;

	Stack s1;
	s1.push(5);
	s1.push(6);
	s1.push(22); 
	s1.push(13);

	s1.print();
	std::cout << "pop element from stack: " << s1.pop() << std::endl;
	s1.print();

	s1.push(17);
	s1.push(99);
	s1.push(88);
	s1.push(88);
	s1.push(88);
	s1.push(88);
	s1.push(88);
	s1.push(88);
	s1.push(88);
	s1.print();
	s1.reset();
	s1.pop();



	return 0;
}

