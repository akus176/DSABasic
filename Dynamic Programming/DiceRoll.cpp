/*Có n xúc xắc, mỗi xúc xắc có 6 mặt được đánh số từ 1 đến 6
Tính số cách để đạt được tổng S khi thảy tất cả các xúc xắc
Ví dụ có 2 xúc xắc thì số cách để đạt được tổng bằng 7 khi thảy
cả hai xúc sắc là 6 cách: 1 + 6, 2 + 5, 3 + 4, 4 + 3, 5 + 2, 6 + 1*/

#include <iostream>

using namespace std;


int DiceRollProblem(int n, int S) {
    // Tạo mảng dp
    int** dp = new int*[n+1];
    
    for(int i = 0; i <= n; i++){
        dp[i] = new int[S + 1](); // Khởi tạo các giá trị trong mảng bằng 0
    }

    // Bài toán cơ sở
    dp[0][0] = 1; // Có một cách đạt được tổng 0 với 0 xúc xắc

    for(int j = 1; j <= S; j++){
        dp[0][j]= 0; // Có không xúc xắc thì không thể đạt tổng lớn hơn không
    }

    // Xây dựng mảng dp: dp[i][j] mang ý nghĩa là số cách để đạt được tổng j với i xúc xắc

    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= S; j++){
            for(int k = 1; k <= 6; k++){ // Duyệt qua số mặt xúc xắc
                if(k <= j) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
    }

    int result = dp[n][S];

    for(int i = 0; i <= n; i++){
        delete[] dp[i];
    }

    delete[] dp;

    return result;
}

int main() {
    int n = 2, S = 7;
    cout << DiceRollProblem(n, S);

    return 0;
}