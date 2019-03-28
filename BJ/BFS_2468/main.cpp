#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];
int visit[101][101];
int max_ = -1000000000;
int max_2 = 1;
int min_ = 1000000000;

void dfs(int x, int y){
    visit[x][y] = 1;

    if(visit[x+1][y] == 0 && x+1 < n)
        dfs(x+1, y);
    if(visit[x-1][y] == 0 && x-1 >= 0)
        dfs(x-1, y);
    if(visit[x][y+1] == 0 && y+1 < n)
        dfs(x, y+1);
    if(visit[x][y-1] == 0 && y-1 >= 0)
        dfs(x, y-1);
}

int cnt_arr(int x){
    int m = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                dfs(i, j);
                m++;
            }
        }
    }

    max_2 = max(max_2, m);
}

void bfs(int x, int y, int z){
    queue<pair<int, int> > q;
    q.push({x, y});

    visit[x][y] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;

        q.pop();

        if(arr[x+1][y] <= z && visit[x+1][y] == 0 && x+1 < n){
            visit[x+1][y] = 1;
            q.push({x+1, y});
        }
        if(arr[x-1][y] <= z && visit[x-1][y] == 0 && x-1 >= 0){
            visit[x-1][y] = 1;
            q.push({x-1, y});
        }
        if(arr[x][y+1] <= z && visit[x][y+1] == 0 && y+1 < n){
            visit[x][y+1] = 1;
            q.push({x, y+1});
        }
        if(arr[x][y-1] <= z && visit[x][y-1] == 0 && y-1 >= 0){
            visit[x][y-1] = 1;
            q.push({x, y-1});
        }
    }
}

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            max_ = max(max_, arr[i][j]);
            min_ = min(min_, arr[i][j]);
        }
    }

    for(int k=min_; k<max_; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visit[i][j] == 0 && arr[i][j] <= k){
                    bfs(i, j, k);
                }
            }
        }

        cnt_arr(k);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visit[i][j] = 0;
            }
        }
    }

    cout << max_2 << endl;

    return 0;
}
