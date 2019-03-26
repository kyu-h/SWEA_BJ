#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int visit[101][101];
int min_ = 1000000000;
int cnt = 1;
queue<pair<pair<int, int>, int>> q;

void bfs(int x, int y, int z){
    visit[x][y] = 1;
    q.push({{x, y}, z});

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;

        q.pop();

        if(arr[x+1][y] == 1 && x+1 < n && visit[x+1][y] == 0){
            q.push({{x+1, y}, z+1});
            visit[x+1][y] = 1;
        }
        if(arr[x-1][y] == 1 && x-1 >= 0 && visit[x-1][y] == 0){
            q.push({{x-1, y}, z+1});
            visit[x-1][y] = 1;
        }
        if(arr[x][y+1] == 1 && y+1 < m && visit[x][y+1] == 0){
            q.push({{x, y+1}, z+1});
            visit[x][y+1] = 1;
        }
        if(arr[x][y-1] == 1 && y-1 >= 0 && visit[x][y-1] == 0){
            q.push({{x, y-1}, z+1});
            visit[x][y-1] = 1;
        }

        if(x == n-1 && y == m-1){
            min_ = z;
            return;
        }
    }
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs(0, 0, 1);

    cout << min_ << endl;

    return 0;
}
