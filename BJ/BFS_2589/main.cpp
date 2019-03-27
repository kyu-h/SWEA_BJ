#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char arr[51][51];
int visit[51][51];
int max_ = -1000000000;
vector <int> v;

bool desc(int x, int y){
    return x > y;
}

void bfs(int x, int y, int z){
    queue<pair<pair<int, int>, int>> q;
    visit[x][y] = 1;
    q.push({{x, y}, z});

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;

        q.pop();

        if(arr[x+1][y] == 'L' && x+1 < n && visit[x+1][y] == 0){
            visit[x+1][y] = 1;
            q.push({{x+1, y}, z+1});
        }
        if(arr[x-1][y] == 'L' && x-1 >= 0 && visit[x-1][y] == 0){
            visit[x-1][y] = 1;
            q.push({{x-1, y}, z+1});
        }
        if(arr[x][y+1] == 'L' && y+1 < m && visit[x][y+1] == 0){
            visit[x][y+1] = 1;
            q.push({{x, y+1}, z+1});
        }
        if(arr[x][y-1] == 'L' && y-1 >= 0 && visit[x][y-1] == 0){
            visit[x][y-1] = 1;
            q.push({{x, y-1}, z+1});
        }

        max_ = max(max_, z);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j] = 0;
        }
    }

    //cout << max_ << endl;
    v.push_back(max_);
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

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j] && arr[i][j] == 'L'){
                bfs(i, j, 1);
            }
        }
    }

    sort(v.begin(), v.end(), desc);

    cout << v[0] - 1 << endl;

    return 0;
}
