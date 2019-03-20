#include <iostream>

using namespace std;

int main(){
    int n,x,y;
    char a;
    cin >> n;

    for(int i=0; i<n; i++){
        scanf("%d%c%d", &x, &a, &y);
        printf("%d\n", x+y);
    }

    return 0;
}
