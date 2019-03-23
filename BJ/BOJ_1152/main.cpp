#include <iostream>

using namespace std;

char a[1000001];
int cnt, length, space;

int main(){
    gets(a);

    while(1){
        if(a[length++] == 0){
            break;
        }
    }

    for(int i=0; i<length; i++){
        if(a[i-1] != 32 && a[i] == 32 && a[i+1] != 32 && i-1 >=0 && i+1 < length-1){
            space++;
        }
    }


    printf("%d\n", space+1);

    return 0;
}
