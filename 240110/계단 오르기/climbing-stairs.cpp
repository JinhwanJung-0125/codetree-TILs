#include <iostream>
#define MAX 1001

using namespace std;

int n;
int memo[MAX];

int DP(int idx) {
    // 종료 조건. n층 높이에 도달했으면 1을, n보다 높게 올라갔으면 0을 return한다.
    if(n == idx) {
        return 1;
    }
    if(n < idx) {
        return 0;
    }

    // 미리 저장된 값이 있으면 그 값을 return한다.
    if(memo[idx] != 0) {
        return memo[idx];
    }

    // 점화식. 현재 위치에서 n층까지 가는 경우의 수는 
    // (현재 위치 + 2)에서 n층까지 가는 경우의 수 + (현재 위치 + 3)에서 n층까지 가는 경우의 수
    memo[idx] = (DP(idx + 2) + DP(idx + 3)) % 10007;

    return memo[idx];
}

int main() {
    cin >> n;

    int answer = DP(0);

    if(answer == 0) {
        cout << 0;
    }
    else{
        cout << answer;
    }

    return 0;
}