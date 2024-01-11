#include <iostream>
#define MAX 1001
#define MOD 1000000007

using namespace std;

int n;
// 계산 과정에서 int 범위를 초과할 수 있으므로 long long으로 선언한다.
long long dp[MAX];

int main() {
    cin >> n;

    dp[0] = 1; dp[1] = 2;

    // dp 점화식은 dp[0] = 1, dp[1] = 2일 때, (2 * 0 크기일 때 경우의 수 1 [아무것도 놓지 않음] / 2 * 1 크기일 때 경우의 수 2)
    // dp[n] = ((dp[n - 1] * 2) + (dp[n - 2] * 2) + 2 * (dp[n - 3] + dp[n - 4] + ... + dp[1] + dp[0])) 이다.

    for(int idx = 2; idx <= n; idx++) {
        dp[idx] = ((dp[idx - 1] * 2) + (dp[idx - 2] * 3)) % MOD;

        for(int part_idx = idx - 3; part_idx >= 0; part_idx--) {
            dp[idx] = ((dp[idx] + dp[part_idx] * 2) % MOD);
        }

    }

    cout << dp[n];

    return 0;
}