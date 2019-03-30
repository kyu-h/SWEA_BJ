#include <iostream>

using namespace std;

int n, m;
int arr[21][21];
int visit[91];
int max_ = -1000000;

void dfs(int x, int y, int z){
    int a = arr[x][y];
    visit[a] = 1;

    if(x+1 < n){
        int b = arr[x+1][y];
        if(visit[b] == 0)
            dfs(x+1, y, z+1);
    }
    if(x-1 >= 0){
        int b = arr[x-1][y];
        if(visit[b] == 0)
            dfs(x-1, y, z+1);
    }
    if(y+1 < m){
        int b = arr[x][y+1];
        if(visit[b] == 0)
            dfs(x, y+1, z+1);
    }
    if(y-1 >= 0){
        int b = arr[x][y-1];
        if(visit[b] == 0)
            dfs(x, y-1, z+1);
    }
    visit[a] = 0;

    max_ = max(max_, z);
}

int main(void){
    cin >> n >> m;

    char c = '0';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> c;
            arr[i][j] = c;
        }
    }

    dfs(0, 0, 1);

    cout << max_ << endl;

    return 0;
}
