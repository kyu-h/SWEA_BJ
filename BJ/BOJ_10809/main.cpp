#include <iostream>
#include <stdio.h>

using namespace std;

string a;
int arr[26];

int main(){
    cin >> a;

    int leng = a.length();

    for(int i=0; i<26; i++){
        arr[i] = -1;
    }

    for(int i=0; i<leng; i++){
        int b = a[i] - 97;
        if(arr[b] == -1)
            arr[b] = i;
    }

    for(int i=0; i<26; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
