#include <iostream>
#include <clocale>

template <typename T, size_t N>
class ArrayTransformer {
public:
    ArrayTransformer() {
        inputArray();
        transformArray();
    }

    void printOriginalArray() const {
        std::wcout << L"Оригінальний масив: ";
        for (size_t i = 0; i < N; ++i) {
            std::wcout << originalArray[i] << L' ';
        }
        std::wcout << std::endl;
    }

    void printTransformedArray() const {
        std::wcout << L"Перетворений масив: ";
        for (size_t i = 0; i < N; ++i) {
            std::wcout << transformedArray[i] << L' ';
        }
        std::wcout << std::endl;
    }

private:
    T originalArray[N];
    char transformedArray[N];

    void inputArray() {
        std::wcout << L"Введіть " << N << L" елементів масиву типу " << typeid(T).name() << L":\n";
        for (size_t i = 0; i < N; ++i) {
            std::wcout << L"Елемент " << i + 1 << L": ";
            std::wcin >> originalArray[i];
        }
    }

    void transformArray() {
        for (size_t i = 0; i < N; ++i) {
            transformedArray[i] = static_cast<char>(originalArray[i]);
        }
    }
};

int main() {
    // Встановлення української локалізації для командного рядка
    setlocale(LC_ALL, "uk_UA.UTF-8");

    ArrayTransformer<int, 5> intTransformer;
    intTransformer.printOriginalArray();
    intTransformer.printTransformedArray();

    ArrayTransformer<double, 5> doubleTransformer;
    doubleTransformer.printOriginalArray();
    doubleTransformer.printTransformedArray();

    return 0;
}

