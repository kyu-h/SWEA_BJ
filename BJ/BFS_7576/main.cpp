#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
int visit[1001][1001];
int max_ = -1000000000;

queue<pair<pair<int, int>, int>>q;

void bfs(int x, int y, int z){
    q.push({{x, y}, z});
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;

        q.pop();

        if(arr[x+1][y] == 0 && visit[x+1][y] == 0 && x+1 < m){
            visit[x+1][y] = 1;
            q.push({{x+1, y}, z+1});
        }
        if(arr[x-1][y] == 0 && visit[x-1][y] == 0 && x-1 >= 0){
            visit[x-1][y] = 1;
            q.push({{x-1, y}, z+1});
        }
        if(arr[x][y+1] == 0 && visit[x][y+1] == 0 && y+1 < n){
            visit[x][y+1] = 1;
            q.push({{x, y+1}, z+1});
        }
        if(arr[x][y-1] == 0 && visit[x][y-1] == 0 && y-1 >= 0){
            visit[x][y-1] = 1;
            q.push({{x, y-1}, z+1});
        }

        max_ = max(max_, z);
    }
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && visit[i][j] == 0){
                q.push({{i, j}, 0});
                visit[i][j] = 1;
            }
            else if(arr[i][j] == -1)
                visit[i][j] = 1;
        }
    }

    int a = q.front().first.first;
    int b = q.front().first.second;
    int c = q.front().second;

    bfs(a, b, c);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == 0){
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    cout << max_ << endl;

    return 0;
}
