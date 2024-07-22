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

void BubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    BubbleSort(a, n);

    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}