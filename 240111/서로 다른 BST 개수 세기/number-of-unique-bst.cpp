#include <iostream>
#define MAX 20

using namespace std;

int n;
int dp[MAX];

int main() {
    cin >> n;

    // DP 점화식은 dp[0] = 1, dp[1] = 1, dp[2] = 2 일때, 
    // (아무것도 없는 경우 1, 하나의 숫자로 BST를 이루는 경우 1, 2개의 숫자로 BST를 이루는 경우 2)
    // dp[n] = (dp[n - 1] * dp[0]) + (dp[n - 2] * dp[1]) + (dp[n - 3] * dp[2]) + ... + (dp[1] * dp[n - 2]) + (dp[0] * dp[n - 1]) 이다.
    // 중복되는 경우의 수 계산을 절약하기 위해 (n / 2) 전까지만 덧셈 계산을 진행하고
    // 짝수의 경우 (지금까지 더한 수 * 2)로, 홀수의 경우 (지금까지 더한 수 * 2 + dp[n / 2]^2)로 빠르게 계산한다.
    dp[0] = 1; dp[1] = 1; dp[2] = 2;

    for(int idx = 3; idx <= n; idx++) {
        for(int i = 0; i < (idx / 2); i++) {
            dp[idx] += (dp[i] * dp[idx - i - 1]);
        }

        if(idx % 2 == 0) {
            dp[idx] = 2 * dp[idx];
        }
        else {
            dp[idx] = 2 * dp[idx] + (dp[idx / 2] * dp[idx / 2]);
        }
    }

    cout << dp[n];

    return 0;
}