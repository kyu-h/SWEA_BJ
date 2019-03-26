#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k;
int cnt = 1;
int arr[101][101];
int visit[101][101];
queue<pair<int, int>> q;

void bfs(int x, int y){
    visit[x][y] = 1;
    q.push({x, y});

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;

        q.pop();

        if(arr[x+1][y] == 0 && x+1 < m && visit[x+1][y] == 0){
            q.push({x+1, y});
            visit[x+1][y] = 1;
            cnt++;
        }

        if(arr[x-1][y] == 0 && x-1 >= 0 && visit[x-1][y] == 0){
            q.push({x-1, y});
            visit[x-1][y] = 1;
            cnt++;
        }

        if(arr[x][y+1] == 0 && y+1 < n && visit[x][y+1] == 0){
            q.push({x, y+1});
            visit[x][y+1] = 1;
            cnt++;
        }

        if(arr[x][y-1] == 0 && y-1 >= 0 && visit[x][y-1] == 0){
            q.push({x, y-1});
            visit[x][y-1] = 1;
            cnt++;
        }

    }
}

int main(void){
    vector<int> t;
    cin >> m >> n >> k;

    for(int x=0; x<k; x++){
        int a, b, c, d = 0;
        cin >> a >> b >> c >> d;

        for(int i=b; i<d; i++){
            for(int j=a; j<c; j++){
                arr[i][j] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0 && visit[i][j] == 0){
                bfs(i, j);
                t.push_back(cnt);
                cnt = 1;
            }
        }
    }

    cout << t.size() << endl;

    sort(t.begin(), t.end());

    for(int i=0; i<t.size(); i++){
        cout << t[i] << " ";
    }

    return 0;
}
