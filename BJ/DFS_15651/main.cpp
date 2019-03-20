#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;

void dfs(){
    if(v.size() == m){
        for(int i=0; i<m; i++)
            printf("%d ", v[i]);
        printf("\n");

        return;
    }

    for(int i=1; i<n+1; i++){
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}

int main(void){
    cin >> n >> m;
    dfs();

    return 0;
}
