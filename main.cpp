#include <iostream>
using namespace std;

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);

// ��������� value � ������ �������
int* push_front(int* arr, int& n, int value)
{
    int* newArr = new int[n + 1];
    newArr[0] = value;
    for (int i = 0; i < n; i++)
        newArr[i + 1] = arr[i];
    delete[] arr;
    n++;
    return newArr;
}

// ��������� value �� ������� index 
int* insert(int* arr, int& n, int index, int value)
{
    if (index < 0 || index > n)
        return arr; // ������������ ������, ������ ������� ��� ���������

    int* newArr = new int[n + 1];
    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];
    newArr[index] = value;
    for (int i = index; i < n; i++)
        newArr[i + 1] = arr[i];

    delete[] arr;
    n++;
    return newArr;
}

// ������� ��������� ������� �������
int* pop_back(int* arr, int& n)
{
    if (n == 0) return arr;
    int* newArr = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
        newArr[i] = arr[i];
    delete[] arr;
    n--;
    return newArr;
}

// ������� ������ ������� �������
int* pop_front(int* arr, int& n)
{
    if (n == 0) return arr;
    int* newArr = new int[n - 1];
    for (int i = 1; i < n; i++)
        newArr[i - 1] = arr[i];
    delete[] arr;
    n--;
    return newArr;
}

// ������� ������� �� ������� 
int* erase(int* arr, int& n, int index)
{
    if (index < 0 || index >= n) return arr;

    int* newArr = new int[n - 1];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i != index)
        {
            newArr[j++] = arr[i];
        }
    }
    delete[] arr;
    n--;
    return newArr;
}

int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "������� ������ �������: "; cin >> n;
    int* arr = new int[n];
    Fillrand(arr, n);
    Print(arr, n);

    int value;
    cout << "������� ��������: "; cin >> value;

 
    arr = push_front(arr, n, value);
    Print(arr, n);

    // ������ � 2
    arr = insert(arr, n, 2, value);
    Print(arr, n);

    
    arr = pop_back(arr, n);
    Print(arr, n);

  
    arr = pop_front(arr, n);
    Print(arr, n);

    // ������ � 1
    arr = erase(arr, n, 1);
    Print(arr, n);

    delete[] arr;
    return 0;
}

void Fillrand(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
