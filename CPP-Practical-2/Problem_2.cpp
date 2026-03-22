#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> a(N);
        for (int &x : a) cin >> x;

        int ans = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int temp = ans | (1 << bit);
            int cnt = 0;

            for (int x : a)
                if ((x & temp) == temp)
                    cnt++;

            if (cnt >= K)
                ans = temp;
        }

        cout << ans << "\n";
    }
}
