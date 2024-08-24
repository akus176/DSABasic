/* Cho một dãy số, tìm xem có dãy con nào có tổng bằng S hay không
Trả về true nếu có và false nếu không */

#include <iostream>
#include <vector>

using namespace std;

void trace(bool** dp, int* a, int n, int S) {
    vector<int> result;

    // Truy vết bằng cách xem xét có đạt được tổng S khi không cần phần tử thứ i không
    int i = n, j = S;
    while(i > 0 && j > 0) {
        if(dp[i-1][j]) { //Nếu đã đạt được tổng j từ trước đó thì rõ ràng phần tử thứ a[i] là không cần thiết
            i--;
        }
        else { //Nếu không có phần tử thứ a[i] sẽ không đạt được tổng j thì rõ ràng phần tử thứ a[i] là cần thiết
            result.push_back(a[i-1]);
            j -= a[i-1];
            i--;
        }
    }

    for(int k = result.size() - 1; k >= 0; k--){
        cout << result[k] << " ";
    }

    cout << endl;
}

bool SubsetSumProblem(int *a, int n, int S){
    bool** dp = new bool*[n+1];

    for(int i = 0; i<= n; i++){
        dp[i] = new bool[S+1];
    }

    // Bài toán cơ sở

    // Có thể tạo được dãy con 0 phẩn tử để cho tổng bằng 0
    dp[0][0] = 1;
    // Không thể tạo được tổng bằng j > 0 nếu không chọn phần tử nào
    for(int j = 1; j <= S; j++){
        dp[0][j] = 0;
    }

    // Xây dựng quy hoạch động
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= S; j++) {
            if(dp[i-1][j]) {
                dp[i][j] = 1;
            }
            else if(dp[i-1][j-a[i-1]] && j >= a[i-1]) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    bool result = dp[n][S];

    if(result) {
        trace(dp, a, n, S);
    }

    for(int i =0; i <= n; i++){
        delete[] dp[i];
    }

    delete[] dp;

    return result;
}

int main() {
    int a[] = {2, 1, 5, 3, 17, 6, 21, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int S = 14;

    if(SubsetSumProblem(a, n, S)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
