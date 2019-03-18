#include <iostream>

using namespace std;

int n;
int arr[5][5];
int t_cnt = 0;
int arr_cnt[10000000];
int m = 0;

void dfs(int x, int y, int p_t_cnt, int p_cnt){
    if(p_cnt == 7){
        arr_cnt[p_t_cnt] = 1;
        return;
    }

    p_t_cnt *= 10;
    p_t_cnt += arr[x][y];

    if(x - 1 >= 0)
        dfs(x-1, y, p_t_cnt, p_cnt+1);
    if(x + 1 <= 3)
        dfs(x+1, y, p_t_cnt, p_cnt+1);
    if(y - 1 >= 0)
        dfs(x, y-1, p_t_cnt, p_cnt+1);
    if(y + 1 <= 3)
        dfs(x, y+1, p_t_cnt, p_cnt+1);
}

int main(void){
    cin >> n;

    for(int z=0; z<n; z++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> arr[i][j];
            }
        }

        for(int i=0;i<10000000;i++){
            arr_cnt[i] = 0;
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                dfs(i, j, 0, 0);
            }
        }

        int cnt = 0;

        for(int i=0;i<10000000;i++){
            if (arr_cnt[i] != 0)
                cnt++;
        }

        printf("#%d %d\n", z+1, cnt);
    }

    return 0;
}
