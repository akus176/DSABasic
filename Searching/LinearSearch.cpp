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

int LinearSearch(int a[], int n, int value) {
    for(int i = 0; i < n; i++) {
        if(a[i] == value) return i;
    }

    return -1;
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang mot chieu vua tao: " << endl;
    printArray(a, n);
    cout << endl;

    int pos = LinearSearch(a, n, 17);

    if(pos == -1) {
        cout << "Khong ton tai phan tu co gia tri 17 trong mang";
    }
    else {
        cout << "Vi tri cua phan tu co gia tri 17 trong mang: " << pos;
    }

    return 0;
}