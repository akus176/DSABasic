/* Bài toán cho ta một xâu ký tự, yêu cầu in ra xâu con đối xứng dài nhất */

#include <iostream>
#include <utility>

using namespace std;

void LPS(string s){
    if(s.size() == 0) {
        cout << "Xau rong";
        return;
    }

    int n = s.size();

    bool** dp = new bool* [n];

    for(int i = 0; i < n; i++){
        dp[i] = new bool[n]();
    }

    // Bài toán cơ sở
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Xấy dựng quy hoạch động
    int maxLen = 1;
    pair<int, int> pos = {0, 0}; 

    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n - len; i++) {
            int j = len + i - 1;

            if(s[i] != s[j]) continue;
            else {
                if(len == 2) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1];
            }

            if((dp[i][j]) && len > maxLen){
                maxLen = len;
                pos = {i ,j};
            }
        }
    }

    // In ra kết quả
    if(pos.first == pos.second) {
        cout << "Khong ton tai xau con doi xung nao co do dai lon hon 1";
    }
    else {
        cout << "Xau con doi xung dai nhat la: ";
        for(int i = pos.first; i <= pos.second; i++){
            cout << s[i];
        }
    }

}

int main() {
    string s = "acbcdadcca";
    LPS(s);

    return 0;
}