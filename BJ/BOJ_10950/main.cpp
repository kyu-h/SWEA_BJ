#include <iostream>

using namespace std;

int main(){
    int x,y,n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        printf("%d\n", x+y);
    }
    return 0;
}
