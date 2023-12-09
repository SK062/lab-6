#include <iostream>
#include <clocale>

template <typename T, size_t N>
T findAverage(const T(&arr)[N]) {
    T sum = 0;

    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }

    return sum / static_cast<T>(N);
}

int main() {
    const int maxSize = 5; // Максимальний розмір масиву

    int intArray[maxSize];
    double doubleArray[maxSize];

    // Встановлення української мови для командного рядка
    setlocale(LC_ALL, "uk_UA.UTF-8");

    // Введення цілих чисел
    std::wcout << L"Введіть " << maxSize << L" цілих чисел:\n";
    for (int i = 0; i < maxSize; ++i) {
        std::wcout << L"Елемент " << i + 1 << L": ";
        std::wcin >> intArray[i];
    }

    // Виведення середнього арифметичного для цілих чисел
    std::wcout << L"Середнє арифметичне для масиву intArray: " << findAverage(intArray) << std::endl;

    // Введення чисел з плаваючою точкою
    std::wcout << L"Введіть " << maxSize << L" чисел з плаваючою точкою:\n";
    for (int i = 0; i < maxSize; ++i) {
        std::wcout << L"Елемент " << i + 1 << L": ";
        std::wcin >> doubleArray[i];
    }

    // Виведення середнього арифметичного для чисел з плаваючою точкою
    std::wcout << L"Середнє арифметичне для масиву doubleArray: " << findAverage(doubleArray) << std::endl;

    return 0;
}
