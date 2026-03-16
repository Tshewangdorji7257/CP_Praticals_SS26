#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N,target;
    cin >> N >> target;

    vector<int> arr(N);

    for(int i=0;i<N;i++)
        cin >> arr[i];

    int total = 1<<N;
    int count = 0;

    for(int mask=0; mask<total; mask++){

        int sum=0;

        for(int i=0;i<N;i++){
            if(mask & (1<<i))
                sum += arr[i];
        }

        if(sum == target)
            count++;
    }

    cout << count;
}
