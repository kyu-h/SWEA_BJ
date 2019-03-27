#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10001];

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(next_permutation(arr, arr + n)){
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
    }else
        cout << "-1";

    return 0;
}
