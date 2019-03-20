#include <iostream>

using namespace std;

string a;

int main(){
    int c;
    cin >> c;
    int num = 0;
    cin >> a;

    for(int i=0; i<c; i++){
        if(a[i] == '1')
            num += 1;
        else if(a[i] == '2')
            num += 2;
        else if(a[i] == '3')
            num += 3;
        else if(a[i] == '4')
            num += 4;
        else if(a[i] == '5')
            num += 5;
        else if(a[i] == '6')
            num += 6;
        else if(a[i] == '7')
            num += 7;
        else if(a[i] == '8')
            num += 8;
        else if(a[i] == '9')
            num += 9;
        else if(a[i] == '0')
            num += 0;
    }

    printf("%d\n", num);

    return 0;
}
