#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visit[100001];

void bfs(int z){
    queue<pair<int, int>> q;
    q.push({n, z});
    visit[n] = 1;

    while(!q.empty()){
        n = q.front().first;
        z = q.front().second;

        if(n == k){
            cout << z << endl;
            return ;
        }

        q.pop();

        if(2*n <= 100000 && visit[2*n] == 0){
            q.push({2*n, z+1});
            visit[2*n] = 1;
        }
        if(n-1 >= 0 && visit[n-1] == 0){
            q.push({n-1, z+1});
            visit[n-1] = 1;
        }
        if(n+1 <= 100000 && visit[n+1] == 0){
            q.push({n+1, z+1});
            visit[n+1] = 1;
        }
    }
}

int main(void){
    cin >> n >> k;

    bfs(0);

    return 0;
}
