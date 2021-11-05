#include <iostream>
#include <cassert>
#include <vector>

#include "Card.cpp"

/* Задание 1
* Добавить в контейнерный класс, который был написан в этом уроке, методы:
* для удаления последнего элемента массива (аналог функции pop_back() в векторах)
* для удаления первого элемента массива (аналог pop_front() в векторах)
* для сортировки массива
* для вывода на экран элементов.
*/


class DataContainer {
    int* data;
    int size;
    int capacity;
    int& operator[](int idx) { }

public:
    DataContainer() : size(0), data(nullptr) {
        capacity = 0;
    }
    DataContainer(int _size) : size(_size) {
        if (_size == 0) {
            DataContainer();
        }
        else if (_size > 0) {
            data = new int[_size];
            capacity = 0;
        }
        else {
            printf("Bad things happened!\n");
            DataContainer();
        }
    }
    ~DataContainer() {
        delete[] data;
    }
    void erase()
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void setData(int idx, int value) {
        assert(idx >= 0 && idx < size);
        this->data[idx] = value;
    }
    int getData(int idx) const {
        assert(idx >= 0 && idx < size);
        return data[idx];
    }
    int getCapacity() {
        return this->capacity;
    }
    void resize(int newLength) {
        if (newLength == size) return;
        if (newLength <= 0) {
            erase();
            return;
        }

        int* newData = new int[newLength];
        if (size > 0) {
            int elementsToCopy = (newLength > size) ? size : newLength;
            for (int idx = 0; idx < elementsToCopy; ++idx)
                newData[idx] = data[idx];
        }
        delete[] data;

        data = newData;
        size = newLength;
    }

    // ^ До этих пор скопировал из методички / файла с сайта

    void insertLast(int value) {
        resize(size + 1);
        setData(size - 1, value);
    }
    int returnLast() {
        return getData(size - 1);
    }
    int removeLast() {
        int tmpVal = getData(size - 1);
        resize(size - 1);
        return tmpVal;
    }
    int returnFirst() {
        return getData(0);
    }
    int removeFirst() {
        int tmpVal = getData(0);
        for (int i = 1; i < size; ++i)
            data[i - 1] = data[i];

        resize(size - 1);
        return tmpVal;
    }
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << ", " << std::endl;
        }
        std::cout << std::endl;
    }
    void sort() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (data[i] > data[i + 1]) {
                    int t = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = t;
                }
            }
        }
    }
};

/* Задание 3
* Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : вектор указателей карт(удобно использовать вектор, 
* т.к.это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
* метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
* метод Clear, который очищает руку от карт
* метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).
*/

class Hand {
    std::vector<Card*> cards;
public:
    void add(Card* card);
    void clear();
    int GetValue();
};
void Hand::add(Card* card) {
    cards.push_back(card);
};

void Hand::clear() {
    cards.clear();
};

int Hand::GetValue() {
    int result = 0;
    int aces = 0;
    for (auto const& i : cards) {
        if (result < 21 && i->getValue() == ACE) {
            result += 11;
        }
        else {
            result += i->getValue();
        }
    }
    return result;
}

int main()
{
    /* Задание 2
    Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
    */
    std::vector<int> data = { 7,8,3,2,2,3,1,8,12,4,3,8 };
    std::vector<int> helpVec;
    helpVec.push_back(data.at(0));

    for (auto const& i : data) {
        bool isUnique = false;
        for (auto j = helpVec.begin(); j != helpVec.end(); j++)
            if (i == *j) {
                isUnique = true;
            }

        if (!isUnique) {
            helpVec.push_back(i);
        }
    }

    std::cout << "Number of unique values is: " << helpVec.size() << std::endl;


	return 0;
}

