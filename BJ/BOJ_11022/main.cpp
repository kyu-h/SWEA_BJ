#include <iostream>
#include <vector>

using namespace std;

int num;

int main(void){
    int x, y = 0;
    scanf("%d", &num);

    for(int i=1; i<num+1; i++){
        scanf("%d %d", &x, &y);
        printf("Case #%d: %d + %d = %d\n", i, x, y, x+y);
    }

    return 0;
}
