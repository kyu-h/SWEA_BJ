#include <iostream>
#include <vector>

using namespace std;

int n,m;
int cnt = 1;

vector<int> v;

void dfs(){
    if(v.size() == m){
        for(int i=0; i<m; i++){
            printf("%d ", v[i]);
        }printf("\n\n");
        return;
    }

    for(int i=1; i<n+1; i++){
        v.push_back(i);
        printf("cnt: %d | i: %d | size: %d\n", cnt++, i, v.size());
        dfs();
        v.pop_back();
    }
}

int main(void){
    cin >> n >> m;
    dfs();
    return 0;
}
