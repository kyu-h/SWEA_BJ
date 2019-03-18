#include <iostream>
#include <algorithm>

using namespace std;

int n;
int capacity = 0;
int arr[26][26] = {0, };
int inside = 0;
int cnt_arr[169] = {0, };

void dfs(int x, int y){
    capacity++;
    arr[x][y] = 0;

    if(arr[x][y-1] == 1){ //왼쪽
        dfs(x, y-1);
    }
    if(arr[x][y+1] == 1){ //오른쪽
        dfs(x, y+1);
    }
    if(arr[x-1][y] == 1){ //아래
        dfs(x-1 ,y);
    }
    if(arr[x+1][y] == 1){ //위
        dfs(x+1, y);
    }
}

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                capacity = 0;
                dfs(i, j);

                cnt_arr[inside++] = capacity;
            }
        }
    }

    sort(cnt_arr, cnt_arr + inside);

    printf("%d\n", inside);

    for(int i=0; i<inside; i++){
        printf("%d\n", cnt_arr[i]);
    }

    return 0;
}
