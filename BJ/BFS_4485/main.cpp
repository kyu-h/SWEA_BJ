#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[126][126];
int visit[126][126];
int min_ = 1000000000;

void bfs(int z, int x, int y){
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > q;
    visit[x][y] = 1;
    q.push({z, {x, y}});

    while(!q.empty()){
        z = q.top().first;
        x = q.top().second.first;
        y = q.top().second.second;

        if(x == n-1 && y == n-1){
            min_ = min(min_, z);
            break;
        }

        q.pop();

        if(visit[x+1][y] == 0 && x+1 < n){
            visit[x+1][y] = 1;
            q.push({z + arr[x+1][y], {x+1, y}});
        }
        if(visit[x-1][y] == 0 && x-1 >= 0){
            visit[x-1][y] = 1;
            q.push({z + arr[x-1][y], {x-1, y}});
        }
        if(visit[x][y+1] == 0 && y+1 < n){
            visit[x][y+1] = 1;
            q.push({z + arr[x][y+1], {x, y+1}});
        }
        if(visit[x][y-1] == 0 && y-1 >= 0){
            visit[x][y-1] = 1;
            q.push({z + arr[x][y-1], {x, y-1}});
        }

    }
}

int main(void){
    int k = 1;

    while(1){
        cin >> n;
        if(n == 0)
            return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }

        bfs(arr[0][0], 0, 0);

        cout << "Problem " << k++ << ": " << min_ << endl;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visit[i][j] = 0;
            }
        }
        min_ = 1000000000;
    }

    return 0;
}
