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

// Su dung phan hoach Lomuto
int partition(int a[], int left, int right) {
    int pivot = a[right], i = left - 1;

    for(int j = left; j < right; j++) {
        if(a[j] < pivot) {
            // Phan hoach thong qua pivot
            i++;
            swap(a[i], a[j]);
        }
    }

    i++;
    // Dua chot ve giua
    swap(a[i], a[right]);
    return i;
}

void QuickSort(int a[], int left, int right) {
    if(left >= right) return;

    int pos = partition(a, left, right);

    // Phan tu pivot khong nam trong lan phan hoach tiep theo nen khong lay tai vi tri pos
    QuickSort(a, left, pos - 1);
    QuickSort(a, pos + 1, right);
}

int main() {
    int a[100], n = 10;

    createArray(a, n);

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    QuickSort(a, 0, n -1);

    cout << endl << "Mang sau khi sap xep: " << endl;
    printArray(a, n);

    return 0;
}