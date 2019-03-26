#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, cnt;
int arr[26][26];
int visit[26][26];

void bfs(int x, int y){
    visit[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;

        q.pop();

        if(arr[x+1][y] == 1 && x+1 < n && visit[x+1][y] == 0){
            visit[x+1][y] = 1;
            q.push({x+1, y});
            cnt++;
        }
        if(arr[x-1][y] == 1 && x-1 >= 0 && visit[x-1][y] == 0){
            visit[x-1][y] = 1;
            q.push({x-1, y});
            cnt++;
        }
        if(arr[x][y+1] == 1 && y+1 < n && visit[x][y+1] == 0){
            visit[x][y+1] = 1;
            q.push({x, y+1});
            cnt++;
        }
        if(arr[x][y-1] == 1 && y-1 >= 0 && visit[x][y-1] == 0){
            visit[x][y-1] = 1;
            q.push({x, y-1});
            cnt++;
        }
    }
}

int main(void){
    vector<int> v;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && visit[i][j] == 0){
                cnt = 0;
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    cout << v.size() << endl;

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] + 1 << endl;
    }

    return 0;
}
