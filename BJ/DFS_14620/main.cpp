#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num;
int arr[11][11];
int inside_cnt = 0;
int m = 0;
int total_cnt = 0;

void dfs(int x, int y){
    inside_cnt += arr[x][y];
    inside_cnt += arr[x-1][y];
    inside_cnt += arr[x+1][y];
    inside_cnt += arr[x][y-1];
    inside_cnt += arr[x][y+1];
}

void set_num(int x, int y){
    arr[x][y] = 200;
    arr[x-1][y] = 200;
    arr[x+1][y] = 200;
    arr[x][y-1] = 200;
    arr[x][y+1] = 200;
}

int main(){
    cin >> num;
    pair<int, pair<int, int>> p[82];

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cin >> arr[i][j];
        }
    }

    for(int z=0; z<3; z++){
        for(int i=1; i<num-1; i++){
            for(int j=1; j<num-1; j++){
                inside_cnt = 0;
                dfs(i, j);

                p[m++] = make_pair(inside_cnt, make_pair(i, j));
            }
        }

        sort(p, p+m);

        total_cnt += p[0].first;

        set_num(p[0].second.first, p[0].second.second);

        m=0;
    }

    cout << total_cnt << endl;

    return 0;
}
