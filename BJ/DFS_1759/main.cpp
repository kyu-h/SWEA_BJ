#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
char arr[16];
int visit[16];
vector <char> v;

void dfs(int x){
    if(v.size() == l){
        int a = 0;
        int b = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] == 97 || v[i] == 101 || v[i] == 105 || v[i] == 111 || v[i] == 117)
                a = 1;
            else
                b++;
        }

        if(a == 1 && b >= 2){
            for(int i=0; i<v.size(); i++){
                printf("%c", v[i]);
            }printf("\n");
        }

        return ;
    }

    for(int i=x; i<c; i++){
        if(!visit[i]){
            visit[i] = 1;
            v.push_back(arr[i]);
            dfs(i+1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}

int main(void){
    cin >> l >> c;

    for(int i=0; i<c; i++){
        cin >> arr[i];
    }

    sort(arr, arr + c);

    dfs(0);

    return 0;
}
