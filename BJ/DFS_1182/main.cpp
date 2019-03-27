#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[21];
int visit[21];
int cnt;

vector<int> v;

void dfs(int x){
    int sum = 0;

    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }

    for(int i=x; i<n; i++){
        if(!visit[i]){
            visit[i] = 1;
            v.push_back(arr[i]);
            dfs(i+1);
            v.pop_back();
            visit[i] = 0;
        }
    }

    if(sum == m){
        cnt++;
        return;
    }
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    dfs(0);

    if(m == 0)
        cout << cnt-1 << endl;
    else
        cout << cnt << endl;

    return 0;
}
