#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    const int SIZE = 10;
    int arr[SIZE];

    // Заполняем исходный массив случайными числами и выводим его
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;  
        cout << arr[i] << " ";
    }
    cout << endl;

    // Считаем количество четных и нечетных чисел
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
    }

    // Создаем массивы минимально возможного размера
    int* even = new int[evenCount];
    int* odd = new int[oddCount];

    // Заполняем их
    int evenIndex = 0; 
    int oddIndex = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0)
            even[evenIndex++] = arr[i];
        else
            odd[oddIndex++] = arr[i];
    }

    // Выводим массив четных чисел
    cout << "Четные числа: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << even[i] << " ";
    }
    cout << endl;

    // Выводим массив нечетных чисел
    cout << "Нечетные числа: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << odd[i] << " ";
    }
    cout << endl;

    // Освобождаем динамическую память
    delete[] even;
    delete[] odd;

}