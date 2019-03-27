#include <iostream>
#include <vector>

using namespace std;

int n;
int visit[9];
vector<int> v;

void dfs(int x){
    if(v.size() == n){
        for(int i=0; i<v.size(); i++){
            printf("%d ", v[i]);
        }printf("\n");

        return ;
    }

    for(int i=1; i<n+1; i++){
        if(!visit[i]){
            visit[i] = 1;
            v.push_back(i);
            dfs(i+1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}

int main(void){
    cin >> n;

    dfs(1);

    return 0;
}
