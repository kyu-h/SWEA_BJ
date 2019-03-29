#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;

int arr[1000001];
int visit[1000001];

int min_ = 1000000000;

void bfs(int x, int z){
    queue<pair<int, int> > q;
    q.push({x, z});

    visit[x] = 1;

    while(!q.empty()){
        x = q.front().first;
        z = q.front().second;

        if(x == g){
            min_ = z;
            return ;
        }

        q.pop();

        if(x+u <= f && visit[x+u] == 0){
            visit[x+u] = 1;
            q.push({x + u, z+1});
        }
        if(x-d >= 0 && visit[x-d] == 0){
            visit[x-d] = 1;
            q.push({x - d, z+1});
        }
    }
}

int main(){
    cin >> f >> s >> g >> u >> d;

    bfs(s, 0);

    if(min_ != 1000000000){
        cout << min_ << endl;
    }else{
        cout << "use the stairs" << endl;
    }

    return 0;
}
