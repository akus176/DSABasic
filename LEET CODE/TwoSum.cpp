#include <iostream>
using namespace std;

void printArray(int a[], int n) {
    for(int i =0; i < n; i++){
        cout << a[i] << " ";
    }
}

int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

void CoutingSort(int a[], int n) {
    int max = getMax(a, n);

    int* count = new int[max + 1]();

    for(int i =0; i < n; i++ ) {
        count[a[i]]++;
    }

    int idx = 0;
    for(int i = 0; i < max + 1; i++) {
        if(count[i] > 0) {
            for(int j =0; j < count[i]; j++) {
                a[idx++] = i;
            }
        }
    }

    delete count;
}

int BinarySearch(int a[], int n, int value) {
    int left = 0, right = a[n-1], mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(a[mid] > value) {
            right = mid - 1;
        }

        else if(a[mid] > value) {
            left = mid + 1;
        }

        else return mid;
    }
}

int main() {
    int a[5] = {2, 6, 1, 5, 4};

    CoutingSort(a, 5);
    printArray(a, 5);

    int pos = BinarySearch(a, 5, 4);

    cout << endl << pos;

}