#include <iostream>

using namespace std;

string a;

int main(){
    cin >> a;
    int length = a.length();

    for(int i=0; i<length; i++){
        printf("%c", a[i]);
        if(i % 10 == 9)
            printf("\n");
    }

    return 0;
}
