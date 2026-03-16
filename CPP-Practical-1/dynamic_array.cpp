#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> v(N);

    cout << "Enter " << N << " numbers:\n";
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());

    int sum = 0;
    for(int x : v) sum += x;

    cout << "Max: " << mx << endl;
    cout << "Min: " << mn << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
