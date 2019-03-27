#include <iostream>
#include <queue>

using namespace std;

int l, a, b, c, d;

void bfs(int z){
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;

        //cout << a << " " << b << endl;
        q.pop();

        if(a - c <= 0 && b - d <= 0){
            z++;
            cout << l - z << endl;
            return ;
        }

        if(a - c >= 0 && b - d >= 0){
            q.push({a-c, b-d});
            z++;
        }
        if(a - c >= 0 && b - d < 0){
            q.push({a-c, b});
            z++;
        }
        if(a - c < 0 && b - d >= 0){
            q.push({a, b-d});
            z++;
        }
    }
}

int main(void){
    cin >> l >> a >> b >> c >> d;

    bfs(0);

    return 0;
}
