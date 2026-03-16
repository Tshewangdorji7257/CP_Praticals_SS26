#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    priority_queue<int> pq;

    for(int i=0;i<N;i++){
        int x; cin >> x;
        pq.push(x);
    }

    for(int i=0;i<K;i++){
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
