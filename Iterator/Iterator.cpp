// Iterator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};


template <typename T>
class VectorIterator : public Iterator<T> {
public:
    VectorIterator(const std::vector<T>& vector) : vector(vector), index(0) {}

    bool hasNext() const override {
        return index < vector.size();
    }

    T next() override {
        if (hasNext()) {
            return vector[index++];
        }
        else {
            
            throw std::out_of_range("Iterator is at the end");
        }
    }

private:
    const std::vector<T>& vector;
    size_t index;
};

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    Iterator<int>* iterator = new VectorIterator<int>(numbers);

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    delete iterator;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
