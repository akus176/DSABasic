/* Yêu cầu đề bài là tìm số finobacci thứ n
Ở lời giải này, ta mặc địch dãy fibonacci bắt đầu từ 1*/

#include<iostream>

using namespace std;

int fibonacci(int n) {

    // Giả sử như số đầu tiên của dãy fibonacci là số thứ nhất
    if(n == 0) return -1;

    int* fibo = new int[n+1];

    // Bài toán cơ sở
    fibo[1] = 1, fibo[2] = 1;

    // Xây dựng quy hoạch động
    for(int i = 3; i <= n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int res = fibo[n];
    
    delete[] fibo;

    return res;
}

int main() {
    cout << "So fibonacci thu 10 la: " << fibonacci(10);
    return 0;
}