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

void merge(int a[], int left, int right, int mid) {
    int* temp = new int[right - left + 1];
    int i = left, j = mid + 1, idx = 0;

    while(i <= mid || j <= right) {
        if(i > mid) temp[idx++] = a[j++];
        else if(j > right) temp[idx++] =a[i++];
        else if(a[i] < a[j]) temp[idx++] = a[i++];
        else if(a[i] >= a[j]) temp[idx++] = a[j++];
    }

    for(int i = 0; i < idx; i++) {
        a[i + left] = temp[i];
    }

    delete[] temp;
}

void MergeSort(int a[], int left, int right) {
    if(left >= right) return;

    int mid = (left + right)/2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    merge(a, left, right, mid);
}

int BinarySearch(int a[], int n, int value) {
    int left = 0, right = n - 1, mid;

    while(left <= right) {
        mid = (left + right)/2;

        if(a[mid] == value) return mid;
        else if(a[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    MergeSort(a, 0, n-1);

    cout << "Mang mot chieu da duoc sap xep: " << endl;
    printArray(a, n);
    cout << endl;

    int pos = BinarySearch(a, n, 17);

    if(pos == -1) {
        cout << "Khong ton tai phan tu co gia tri 17 trong mang";
    }
    else {
        cout << "Vi tri cua phan tu co gia tri 17 trong mang: " << pos;
    }

    return 0;
}