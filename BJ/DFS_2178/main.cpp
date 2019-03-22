#include <iostream>

using namespace std;

int n, m;
int arr[101][101];
int visit[101][101];
int min_ = 10001;

void dfs(int x, int y, int cnt){
    printf("%d %d %d\n", x, y, cnt);
    if(x == n-1 && y == m-1){
        min_ = min(cnt, min_);
        return;
    }

    if(visit[x][y] == 0){
        visit[x][y] = 1;

        if(arr[x+1][y] == 1 && x+1 < n)
            dfs(x+1, y, cnt+1);
        if(arr[x-1][y] == 1 && x-1 >= 0)
            dfs(x-1, y, cnt+1);
        if(arr[x][y+1] == 1 && y+1 < m)
            dfs(x, y+1, cnt+1);
        if(arr[x][y-1] == 1 && y-1 >= 0)
            dfs(x, y-1, cnt+1);

        //visit[x][y] = 0;
    }
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    dfs(0, 0, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d", visit[i][j]);
        }printf("\n");
    }

    cout << min_ << endl;

    return 0;
}
