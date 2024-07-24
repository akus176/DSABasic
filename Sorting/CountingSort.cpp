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

    for(int i =0; i<n; i++) {
        a[i] = rand() % 31 + 1;
    }
}

int getMax(int a[], int n) {
    int max = a[0];
    
    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }

    return max;
}
void CountingSort(int a[], int n) {
    int max = getMax(a, n);

    // Khoi tao mang count voi tat ca cac gia tri la 0
    int* count = new int[max + 1]();

    // Dem phan phoi 
    for(int i =0; i < n; i++) {
        count[a[i]]++;
    }

    // Gan lai gia tri cho mang
    int idx = 0;
    for(int i = 0; i < max + 1; i++) {
        if(count[i] > 0) {
            for(int j = 0; j < count[i]; j++) {
                a[idx++] = i;
            }
        }
    }

    delete[] count;
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    CountingSort(a, n);

    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}