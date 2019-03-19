#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[26][26];
int inner_cnt = 0;
int total = 0;

void dfs(int x, int y){
    arr[x][y] = 0;

    if(arr[x+1][y] == 1 && x+1 < n)
        dfs(x+1, y);
    if(arr[x-1][y] == 1 && x-1 >= 0)
        dfs(x-1, y);
    if(arr[x][y+1] == 1 && y+1 < n)
        dfs(x, y+1);
    if(arr[x][y-1] == 1 && y-1 >= 0)
        dfs(x, y-1);

    total++;
}

int main(void){
    cin >> n;
    int arr_n[1000];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                dfs(i, j);
                arr_n[inner_cnt++] = total;
                total = 0;
            }
        }
    }

    cout << inner_cnt << endl;

    sort(arr_n, arr_n + inner_cnt);

    for(int i=0; i<inner_cnt; i++)
        cout << arr_n[i] << endl;

    return 0;
}
