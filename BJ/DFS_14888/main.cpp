#include <iostream>
#include <algorithm>

int n;
int num[12];
int arith[4];
int min_ = 1000000000;
int max_ = -1000000000;

using namespace std;

void dfs(int cnt, int a, int b, int c, int d, int total){
    //cout << cnt << " " << a << " " << b << " " << c << " " << d << " " << total << endl;
    if(cnt == n){
        min_ = min(total, min_);
        max_ = max(total, max_);
        return;
    }

    if(a != 0)
        dfs(cnt+1, a-1, b, c, d, total + num[cnt]);
    if(b != 0)
        dfs(cnt+1, a, b-1, c, d, total - num[cnt]);
    if(c != 0)
        dfs(cnt+1, a, b, c-1, d, total * num[cnt]);
    if(d != 0)
        dfs(cnt+1, a, b, c, d-1, total / num[cnt]);
}

int main(void){
    int total = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    for(int i=0; i<4; i++){
        cin >> arith[i];
    }

    total = num[0];

    dfs(1, arith[0], arith[1], arith[2], arith[3], total);

    cout << max_ <<endl;
    cout << min_ <<endl;

    return 0;
}
