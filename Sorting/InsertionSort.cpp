#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArray(int a[], int n) {
    for(int i =0; i < n;i++){
        cout << a[i] << " ";
    }
}

void createArray(int a[], int n) {
    srand(time(0));

    for(int i =0; i<n;i++) {
        a[i] = rand() % 31 + 1;
    }
}

void InsertionSort(int a[], int n) {
    int key, pos;

    for(int i = 0; i < n; i++) {
        key = a[i];
        pos = i;

        // Tim vi tri cho key
        while(a[pos - 1] > key && pos > 0) {
            // Dich phan tu sang phai de tao khoang trong
            a[pos] = a[pos - 1];
            pos--;
        }

        // Dua phan tu ve dung vi tri
        a[pos] = key;
    }
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    InsertionSort(a, n);
    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}