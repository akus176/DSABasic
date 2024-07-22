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

int getPartition(int a[], int left, int right) {
    int pivot = a[right], i = left - 1;

    for(int j = left; j < right; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    i++;
    swap(a[i], a[right]);
    return i;
}

void QuickSort(int a[], int left, int right) {
    if(left >= right) return;

    int partition = getPartition(a, left, right);

    QuickSort(a, left, partition - 1);
    QuickSort(a, partition + 1, right);
}

int BinarySearchRecursive(int a[],int value, int left, int right) {
    if(left > right) return -1;

    int mid = (left + right)/2;

    if(a[mid] == value) return mid;
    else if(a[mid] > value) return BinarySearchRecursive(a, value, left, mid - 1);
    else return BinarySearchRecursive(a, value, mid + 1, right);
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    QuickSort(a, 0, n-1);

    cout << "Mang mot chieu da duoc sap xep: " << endl;
    printArray(a, n);
    cout << endl;

    int pos = BinarySearchRecursive(a, 17, 0, n - 1);

    if(pos == -1) {
        cout << "Khong ton tai phan tu co gia tri 17 trong mang";
    }
    else {
        cout << "Vi tri cua phan tu co gia tri 17 trong mang: " << pos;
    }

    return 0;
}