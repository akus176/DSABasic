/* Giả sử bài toán chỉ yêu cầu tìm 1 dãy con tăng dài nhất */

#include <iostream>

using namespace std;

int getMax(int a[], int n) {
    int max = a[0];

    for(int i = 1; i < n; i++) {
        if(max < a[i]){
            max = a[i];
        } 
    }

    return max;
}

void trace(int a[], int dp[], int n, int max) {
    int* res = new int[max];

    int index = 0;
    for(; index < n; index++) {
        if(dp[index] == max) break;
    }

    int temp = max, k = max - 1;
    for(int i = index; i >= 0; i--) {
        if(dp[i] == temp) {
            res[k--] = a[i];
            temp--;
        }
    }

    for(int i = 0; i < max; i++) {
        cout << res[i] << " ";
    }

    cout << endl;

    delete[] res;
}

int LIS(int a[], int n) {
    int* dp = new int[n];

    // dp[i] cho ta biết số lượng phần tử của dãy con tăng dài nhất kết thúc ở vị trí i

    // Bài toán cơ sở: Mỗi mảng con có 1 phần tử thì LIS của nó là 1
    for(int i = 0; i < n; i++){
        dp[i] = 1;
    }

    // Xây dựng quy hoạch động
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if( a[j] > a[i] && dp[j] < dp[i] + 1) {
                dp[j] = dp[i] + 1;
            }
        }
    }

    // Tìm kết quả 
    int max = getMax(dp, n);

    trace(a, dp, n, max);

    delete[] dp;

    return max;
}

int main() {
    int a[] = {0, 2, 1, 5, 4, 6, 2};
    int n = sizeof(a)/sizeof(a[0]);

    cout << LIS(a, n);
}