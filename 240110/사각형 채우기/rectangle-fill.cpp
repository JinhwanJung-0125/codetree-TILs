#include <iostream>
#define MAX 1001

using namespace std;

int n;
int memo[MAX];

int DP(int idx) {
    // 종료조건. 사각형 세로 칸이 1칸이면 경우의 수는 1이고
    if(idx == 1) {
        return 1;
    }
    // 사각형 세로 칸이 2칸이면 경우의 수는 2이다.
    if(idx == 2) {
        return 2;
    }

    // 이미 계산된 값이면 그 값을 쓴다.
    if(memo[idx] != 0) {
        return memo[idx];
    }

    // 점화식. 사각형 세로 칸이 idx 일 경우 경우의 수는
    // (idx - 1 칸일때 경우의 수) + (idx - 2 칸일때 경우의 수)
    memo[idx] = (DP(idx - 1) + DP(idx - 2)) % 10007;

    return memo[idx];
}

int main() {
    cin >> n;

    int answer = DP(n);

    cout << answer;

    return 0;
}