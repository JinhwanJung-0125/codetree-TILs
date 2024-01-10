#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int main() {
    cin >> n;
    n -= 1;

    dp.push_back(1);
    dp.push_back(1);

    if(n > 1) {
        for(int i = 2; i <= n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
    }

    cout << dp.back();
    
    return 0;
}