/* Xâu con chung dài nhất giữa hai xâu là xâu con mà cả hai xâu đều chứa. 
Hơn nữa, xâu này không bắt buộc phải chứa những kí tự liên tiếp nhau */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void trace(int** dp) {

}

void printMatrix(int** dp, int m, int n){
    for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void LCS(string X, string Y) {
    if(X.size() == 0 || Y.size() == 0) {
        cout << "Khong ton tai xau con chung dai nhat";
        return;
    }

    int m = X.size(), n = Y.size();
    int** dp = new int*[m + 1];

    for(int i = 0; i < m + 1; i++){
        dp[i] = new int[n+1]();
    }

    // Giá trị của dp[i][j] cho biết độ dài xâu con chung của i ký tự đầu tiên của X và j ký tự đầu tiên của Y

    // Bài toán cơ sở: Khi không chọn ký tự nào ở xâu X thì độ dài xâu con chung là 0
    // bất kể chọn bao nhiêu ký tự từ xâu Y, và ngược lại.
    for(int i = 0; i < m + 1; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j < n + 1; j++){
        dp[0][j] = 0;
    }

    string result = "";

    // Xây dựng quy hoạch động
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(X[i] == Y[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                result += X[i];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    //printMatrix(dp, m, n);
    cout << "Do dai xau con chung dai nhat la: " << dp[m][n];

    // Chưa truy vết

    for(int i = 0; i < m + 1; i++){
        delete[] dp[i];
    }

    delete[] dp;
}

int main() {
    string X = "bdcbdabc", Y = "bdcab";
    LCS(X, Y);
}