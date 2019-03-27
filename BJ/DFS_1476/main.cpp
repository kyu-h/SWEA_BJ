#include <iostream>

using namespace std;

int e, s, m;

void dfs(int x, int y, int z, int year){
    if(x == 16)
        x = 1;
    if(y == 29)
        y = 1;
    if(z == 20)
        z = 1;

    if(x == e && y == s && z == m){
        cout << year << endl;
        return ;
    }

    if(x >= 1 && x <16 && y >= 1 && y <29 && z>=1 && z<20)
        dfs(x+1, y+1, z+1, year+1);
}

int main(void){
    cin >> e >> s >> m;

    dfs(1, 1, 1, 1);

    return 0;
}
