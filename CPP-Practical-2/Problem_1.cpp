#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (a[i] & a[j]) return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> mask(N);

        for (int i = 0; i < N; i++) {
            int M; cin >> M;
            int m = 0;
            while (M--) {
                int x; cin >> x;
                m |= (1 << x);
            }
            mask[i] = m;
        }

        sort(mask.begin(), mask.end());
        bool ok = false;

        do {
            if (valid(mask)) {
                ok = true;
                break;
            }
        } while (next_permutation(mask.begin(), mask.end()));

        cout << (ok ? "YES\n" : "NO\n");
    }
}
