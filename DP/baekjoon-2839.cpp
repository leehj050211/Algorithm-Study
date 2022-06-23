#include <iostream>
using namespace std;
// 백준 2839번 설탕 배달

int memo[5000]; // 설탕을 담기 위해 필요한 봉지의 갯수를 담는 배열
int n;

// 그리디 알고리즘으로 풀면 더 쉽지만 dp문제니까 dp로 풀이
int main() {
    cin >> n;

    if (n % 5 == 0) {// 만약 5로 나누어 떨어지면 바로 출력
        cout << n / 5;
        return 0;
    }

    memo[3] = 1;
    memo[5] = 1;
    for (int i=6; i<=n; i++) {
        if (memo[i-3] != 0) {// 3kg의 봉지로 담을 수 있다면
            memo[i] = memo[i-3] + 1;
        }
        if (memo[i-5] != 0) {// 5kg의 봉지로 담을 수 있다면
            if (memo[i] != 0) {// 이미 3kg의 봉지로 계산 했었다면
                // 무엇이 더 적은 봉지를 사용하는지 확인 후 값을 업데이트
                memo[i] = min(memo[i], memo[i-5]) + 1;
            } else {
                memo[i] = memo[i-5] + 1;
            }
        }
    }
    if (memo[n] == 0) cout << -1;
    else cout << memo[n];
    return 0;
}