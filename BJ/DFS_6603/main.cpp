#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[50];
int visit[50];
int cnt;
int s_arr01[7];

vector<int> v;

void dfs(int b, int a){
    if(a == 6){
        int samp[7] = {0, };
        for(int i=0; i<6; i++){
            s_arr01[i] = v[i];
        }

        sort(s_arr01, s_arr01 + 6);

        for(int i=0; i<6; i++){
            printf("%d ", s_arr01[i]);
        }printf("\n");

        return;
    }

    for(int i=b; i<n; i++){
        if(visit[arr[i]] == 0){
            visit[arr[i]] = 1;
            v.push_back(arr[i]);
            dfs(i, a+1);
            v.pop_back();
            visit[arr[i]] = 0;
        }
    }
}

int main(void){
    while (1){
        cin >> n;
        if(n == 0)
            break;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        dfs(0, 0);

        for(int i=0; i<50; i++)
            visit[i] = 0;

        v.clear();

        printf("\n");
    }

    return 0;
}
