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

void ShellSort(int a[], int n) {
    int pos, key, distance;

    // Tim khoang cach ban dau theo day Shell
    distance = n/2;

    // Giam dan distance
    for(; distance > 0; distance /= 2) {

        // Su dung Insertion Sort cho distance
        for(int i = distance; i < n; i++) {
            key = a[i];
            pos = i;

            while(a[pos - distance] > key && pos - distance >=0) {
                a[pos] = a[pos - distance];
                pos -= distance;
            }

            a[pos] = key;
        }
    }
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    ShellSort(a, n);

    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}