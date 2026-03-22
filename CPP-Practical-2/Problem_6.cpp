#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> toll(N);
    for (int &x : toll) cin >> x;

    vector<vector<int>> dp(N+1, vector<int>(K+1, 1e9));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            if (dp[i][k] == 1e9) continue;

            // pay
            if (M >= toll[i])
                dp[i+1][k] = min(dp[i+1][k], dp[i][k] + 1);

            // skip
            if (k < K)
                dp[i+1][k+1] = min(dp[i+1][k+1], dp[i][k] + 2);
        }
    }

    int ans = 1e9;
    for (int k = 0; k <= K; k++)
        ans = min(ans, dp[N][k]);

    cout << (ans == 1e9 ? -1 : ans);
}
