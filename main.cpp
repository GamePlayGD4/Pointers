#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    const int SIZE = 10;
    int arr[SIZE];

    // ��������� �������� ������ ���������� ������� � ������� ���
    cout << "�������� ������: ";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;  
        cout << arr[i] << " ";
    }
    cout << endl;

    // ������� ���������� ������ � �������� �����
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
    }

    // ������� ������� ���������� ���������� �������
    int* even = new int[evenCount];
    int* odd = new int[oddCount];

    // ��������� ��
    int evenIndex = 0; 
    int oddIndex = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0)
            even[evenIndex++] = arr[i];
        else
            odd[oddIndex++] = arr[i];
    }

    // ������� ������ ������ �����
    cout << "������ �����: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << even[i] << " ";
    }
    cout << endl;

    // ������� ������ �������� �����
    cout << "�������� �����: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << odd[i] << " ";
    }
    cout << endl;

    // ����������� ������������ ������
    delete[] even;
    delete[] odd;

}