#include <iostream>

using namespace std;

int w, h;
int arr[51][51];
int cnt = 0;

void dfs(int x, int y){
    arr[x][y] = 0;

    if(arr[x+1][y] == 1 && x+1 < h)
        dfs(x+1, y);
    if(arr[x-1][y] == 1 && x-1 >= 0)
        dfs(x-1, y);
    if(arr[x][y+1] == 1 && y+1 < w)
        dfs(x, y+1);
    if(arr[x][y-1] == 1 && y-1 >= 0)
        dfs(x, y-1);

    if(arr[x+1][y+1] == 1 && x+1 < h && y+1 < w)
        dfs(x+1, y+1);
    if(arr[x+1][y-1] == 1 && x+1 < h && y-1 >= 0)
        dfs(x+1, y-1);
    if(arr[x-1][y+1] == 1 && x-1 >= 0 && y+1 < w)
        dfs(x-1, y+1);
    if(arr[x-1][y-1] == 1 && x-1 >= 0 && y-1 >= 0)
        dfs(x-1, y-1);
}

int main(void){

    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0)
            return 0;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                arr[i][j] = 0;
            }
        }

        cout << cnt << endl;
        cnt = 0;
    }

    return 0;
}
