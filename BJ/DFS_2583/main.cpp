#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n, k, cnt;
int arr[101][101];

void dfs(int x, int y){
    if (arr[x + 1][y] == 1 && arr[x - 1][y] == 1 && arr[x][y + 1] == 1 && arr[x][y - 1] == 1 &&
         x + 1 >= m && x - 1 < 0 && y + 1 >= n && y - 1 < 0) {
        return;
    }
    cnt++;

    arr[x][y] = 1;

    if(arr[x+1][y] == 0 && x+1 < m)
        dfs(x+1, y);
    if(arr[x-1][y] == 0 && x-1 >= 0)
        dfs(x-1, y);
    if(arr[x][y+1] == 0 && y+1 < n)
        dfs(x, y+1);
    if(arr[x][y-1] == 0 && y-1 >= 0)
        dfs(x, y-1);
}

int main(void){
    vector<int> v;
    cin >> m >> n >> k;

    for(int i=0; i<k; i++){
        int a, b, c, d = 0;

        cin >> a >> b >> c >> d;
        for(int x=b; x<d; x++){
            for(int y=a; y<c; y++){
                arr[x][y] = 1;
            }
        }
    }

    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            if(arr[x][y] == 0){
                cnt = 0;
                dfs(x, y);
                v.push_back(cnt);
            }
        }
    }

    cout << v.size() << endl;

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }cout << endl;

    return 0;
}
