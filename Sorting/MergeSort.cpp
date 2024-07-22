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

void Merge(int a[], int left, int right, int mid) {

    int i = left, j = mid + 1, idx =0;
    int* temp = new int[right - left + 1];

    while(i <= mid || j <= right) {
        if(j > right) {
            temp[idx++] = a[i++];
        }
        else if(i > mid) {
            temp[idx++] = a[j++];
        }
        else if(a[i] > a[j]) {
            temp[idx++] = a[j++];
        }
        else if(a[i] <= a[j]) {
            temp[idx++] = a[i++];
        }
    }

    // Thay doi mang cu thanh moi tu vi tri left
    for(int i = 0; i < idx; i++) {
        a[left + i] = temp[i];
    }

    delete temp;
}

void MergeSort(int a[], int left, int right) {
    if(left >= right) return;

    int mid = (left + right) /2;

    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, right, mid);
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    MergeSort(a, 0, n -1);

    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}