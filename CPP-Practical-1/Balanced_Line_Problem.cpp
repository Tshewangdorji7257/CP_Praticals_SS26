#include <iostream>
#include <deque>
using namespace std;

int main() {
    int q;
    cin >> q;

    deque<int> dq;

    while(q--){
        string op;
        cin >> op;

        if(op=="push_front"){
            int x; cin >> x;
            dq.push_front(x);
        }
        else if(op=="push_back"){
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(op=="pop_front"){
            if(!dq.empty()) dq.pop_front();
        }
        else if(op=="pop_back"){
            if(!dq.empty()) dq.pop_back();
        }

        for(int x : dq)
            cout << x << " ";
        cout << endl;
    }
}
