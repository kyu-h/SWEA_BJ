#include <iostream>

using namespace std;

string a;

int main(){
    while(cin >> a){
        int n = a.length();

        for(int i=0; i<n; i++){
            if(a[i] == '\n'){
                printf("\n");
            }else if(a[i] == ' '){
                printf(" ");
            }else{
                printf("%c", a[i]);
            }
        }
    }

    return 0;
}
