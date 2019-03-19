#include <iostream>

using namespace std;

int length;
int arr[11][11];
int chk[11][11];
int amount = 1000000;

bool check(int x, int y){
    if(chk[x][y] == 1 || chk[x+1][y] == 1 || chk[x-1][y] == 1 || chk[x][y+1] == 1 || chk[x][y-1] == 1)
        return false;
    else
        return true;
}

int getSum(){
    int sum = 0;

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(chk[i][j])
                sum += arr[i][j];
        }
    }
    amount = min(amount, sum);
}

void dfs(int cnt){
    if(cnt == 3)
        return;

    for(int i=1; i<length-1; i++){
        for(int j=1; j<length-1; j++){
            if(check(i,j)){
                chk[i][j] = 1;
                chk[i+1][j] = 1;
                chk[i-1][j] = 1;
                chk[i][j+1] = 1;
                chk[i][j-1] = 1;

                dfs(cnt + 1);
                if(cnt == 2)
                    getSum();

                chk[i][j] = 0;
                chk[i+1][j] = 0;
                chk[i-1][j] = 0;
                chk[i][j+1] = 0;
                chk[i][j-1] = 0;
            }
        }
    }
}

int main(void){
    cin >> length;

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0);

    cout << amount << endl;

    return 0;
}
