#include <iostream>
#include <vector>

using namespace std;

int n;
char arr[101][101];
int visit[101][101];
char color[3] = {'R', 'G', 'B'};
char color_[2] = {'R', 'B'};

vector<int> v;

void dfs(int x, int y, int z){
    visit[x][y] = 1;

    if(arr[x+1][y] == color[z] && visit[x+1][y] == 0 && x+1 < n)
        dfs(x+1, y, z);
    if(arr[x-1][y] == color[z] && visit[x-1][y] == 0 && x-1 >= 0)
        dfs(x-1, y, z);
    if(arr[x][y+1] == color[z] && visit[x][y+1] == 0 && y+1 < n)
        dfs(x, y+1, z);
    if(arr[x][y-1] == color[z] && visit[x][y-1] == 0 && y-1 >= 0)
        dfs(x, y-1, z);
}

void dfs_(int x, int y, int z){
    visit[x][y] = 1;

    if(arr[x+1][y] == color_[z] && visit[x+1][y] == 0 && x+1 < n)
        dfs_(x+1, y, z);
    if(arr[x-1][y] == color_[z] && visit[x-1][y] == 0 && x-1 >= 0)
        dfs_(x-1, y, z);
    if(arr[x][y+1] == color_[z] && visit[x][y+1] == 0 && y+1 < n)
        dfs_(x, y+1, z);
    if(arr[x][y-1] == color_[z] && visit[x][y-1] == 0 && y-1 >= 0)
        dfs_(x, y-1, z);
}

int main(){
    char c = '0';

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            arr[i][j] = c;
        }
    }

    int num = 0;
    int num_ = 0;

    for(int z=0; z<3; z++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && arr[i][j] == color[z]){
                    dfs(i, j, z);
                    num++;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }

    for(int z=0; z<2; z++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && arr[i][j] == color_[z]){
                    dfs_(i, j, z);
                    num_++;
                }
            }
        }
    }

    cout << num << " " << num_ << endl;

    return 0;
}
