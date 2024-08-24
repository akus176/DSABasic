#include <iostream>
#include <algorithm>

using namespace std;

int KnapsackProblem(int value[], int weight[], int size, int capacity) {

    // Tao mang dp
    int** dp = new int*[size + 1];

    for(int i = 0; i <= size; i++){
        dp[i] = new int[capacity + 1];
    }

    // Bai toan con nho nhat
    for(int i = 0; i <= size; i++){
        dp[i][0] = 0; // Neu balo co suc chua la 0 thi gia tri trong balo la 0
    }

    for(int j = 0; j <= capacity; j++){
        dp[0][j] = 0; // Neu khong chon vat pham nao thi gia tri trong balo la 0
    }

    // Xay dung mang dp
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= capacity; j++){

            // Neu balo khong du suc chua thi khong the chon vat pham 
            if(weight[i - 1] > j) { // phai de i - 1 de truy xuat dung chi so
                dp[i][j] = dp[i-1][j];
            }

            // Neu balo du suc chua thi ta xem xet xem viec lua chon vat pham nay
            // co mang lai gia tri cao hon viec khong chon hay khong
            else {
                dp[i][j] = max(dp[i-1][j], (dp[i-1][j - weight[i - 1]] + value[i- 1]));
            }
        }
    }

    int result = dp[size][capacity];

    for(int i = 0; i <= size; i++ ){
        delete[] dp[i];
    }

    delete[] dp;

    return result;
}

int main() {
    int weight[] = {95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    int value[] = {55, 10, 47, 5, 4, 50, 8, 61, 85, 87};
    int size = sizeof(weight)/sizeof(weight[0]);
    int capacity = 269;

    cout << KnapsackProblem(value, weight, size, capacity);

    return 0;
}
