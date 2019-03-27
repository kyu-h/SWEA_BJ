#include <iostream>

using namespace std;

int n;
int arr[101][101];
int visit[101][101];
int cnt;

void dfs_col(int x, int y, int z){
    visit[x][y] = 1;
    if((arr[x][y+1] == 'X' && y+1 < n) || (arr[x][y] == '.' && y+1 == n)){
        if(z > 1)
            cnt++;

        return;
    }

    if(arr[x][y+1] == '.' && y+1 < n && visit[x][y+1] == 0)
        dfs_col(x, y+1, z+1);
    if(arr[x][y-1] == '.' && y-1 >= 0 && visit[x][y-1] == 0)
        dfs_col(x, y-1, z+1);
}

void dfs_row(int x, int y, int z){
    //cout << x << " " << y << " " << z << " " << cnt << " " << endl;
    visit[x][y] = 1;
    if((arr[x+1][y] == 'X' && x+1 < n) || (arr[x][y] == '.' && x+1 == n)){
        if(z > 1)
            cnt++;

        return;
    }

    if(arr[x+1][y] == '.' && x+1 < n && visit[x+1][y] == 0)
        dfs_row(x+1, y, z+1);
    if(arr[x-1][y] == '.' && x-1 >= 0 && visit[x-1][y] == 0)
        dfs_row(x-1, y, z+1);
}

int main(void){
    cin >> n;

    char c = '0';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            arr[i][j] = c;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == '.' && visit[i][j] == 0){
                dfs_col(i, j, 1);
            }
        }
    }

    cout << cnt << " ";

    cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == '.' && visit[i][j] == 0){
                //cout << i << " " << j << endl;
                dfs_row(i, j, 1);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
