//************************
//    Have to do again
//************************
#include <iostream>
#include <algorithm>

using namespace std;

int row, col;
int arr[9][9];
int visit[9][9];

int min_ = 1000000000;

int cnt_arr(){
    int cnt = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 0){
                cnt++;
            }
        }
    }

    min_ = min(min_, cnt);
}

void dfs(int x, int y){
    if(x == row-1 && y == col-1){
        cnt_arr();
        return;
    }


    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            visit[i][j] = 9;
            if(arr[i][j] == 1){
                for()
            }
            if(arr[i][j] == 2){

            }
            if(arr[i][j] == 3){

            }
            if(arr[i][j] == 4){

            }
            if(arr[i][j] == 5){

            }
            dfs(i, j);
            visit[i][j] = 0;
        }
    }
}

int main(void){
    cin >> row >> col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            dfs(i, j);
        }
    }

    cout << min_ << endl;

    return 0;
}
