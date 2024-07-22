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

void SelectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_i = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_i]) {
                min_i = j;
            }
        }

        if(min_i == i) continue;

        swap(a[i], a[min_i]);
    }
}



int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    SelectionSort(a, n);
    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}