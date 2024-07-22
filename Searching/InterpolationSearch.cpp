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

int getMax(int a[], int n) {
    int max = a[0];

    for(int i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }

    return max;
}

void CountingSort(int a[], int n) {
    int max = getMax(a, n);

    int* count = new int[max + 1]();

    for(int i = 0; i < n; i++) {
        count[a[i]]++;
    }

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


int InterpolationSearch(int a[], int n, int value) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) * (value - a[left])/(a[right] - a[left]);

        if(a[mid] == value) return mid;
        else if(a[mid] > value) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    CountingSort(a, n);

    cout << "Mang mot chieu da duoc sap xep: " << endl;
    printArray(a, n);
    cout << endl;

    int pos = InterpolationSearch(a, n, 17);

    if(pos == -1) {
        cout << "Khong ton tai phan tu co gia tri 17 trong mang";
    }
    else {
        cout << "Vi tri cua phan tu co gia tri 17 trong mang: " << pos;
    }

    return 0;
}