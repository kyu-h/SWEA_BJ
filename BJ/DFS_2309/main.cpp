#include <iostream>
#include <algorithm>

using namespace std;

int average = 100;
int arr[10];
int visit[10];
int key[8];

void call(){
    for(int i=0, m=0; i<9; i++){
        if(visit[i])
            key[m++] = arr[i];
    }
}

void dfs(int cnt, int chk, int total){
    if(cnt == 7 && total == average){
        call();
        return;
    }

    visit[chk] = 1;
    total += arr[chk];
    for(int i=1; i<9; i++){
        if(visit[i] == 0)
            dfs(cnt+1, i, total);
    }
    visit[chk] = 0;
}

int main(){
    for(int i=0; i<9; i++){
        cin >> arr[i];
    }

    for(int i=0; i<9; i++){
        dfs(0, i, 0);
    }

    sort(key, key + 7);

    for(int i=0; i<7; i++)
        cout << key[i] << endl;

    return 0;
}
