#include <iostream>
#include <vector>

using namespace std;

int n, m;
int visit[9];

vector<int> v;

void dfs(int x, int y){
    if(y == m){
        for(int i=0; i<m; i++)
            printf("%d ", v[i]);
        printf("\n");

        return;
    }

    for(int i=1; i<n+1; i++){
        if(!visit[i]){
            visit[i] = 1;
            v.push_back(i);
            dfs(x+1, y+1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}

int main(void){
    cin >> n >> m;

    dfs(0, 0);

    return 0;
}
