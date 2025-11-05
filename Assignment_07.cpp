#include <iostream>
using namespace std;

// Template function for Selection Sort
template <class T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to display array
template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    // Integer array
    cout << "Enter number of integers: ";
    cin >> n;
    int intArr[n];
    cout << "Enter integer elements: ";
    for (int i = 0; i < n; i++)
        cin >> intArr[i];

    selectionSort(intArr, n);
    cout << "Sorted integer array: ";
    display(intArr, n);

    // Float array
    cout << "\nEnter number of floats: ";
    cin >> n;
    float floatArr[n];
    cout << "Enter float elements: ";
    for (int i = 0; i < n; i++)
        cin >> floatArr[i];

    selectionSort(floatArr, n);
    cout << "Sorted float array: ";
    display(floatArr, n);

    return 0;
}
