#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n;
char a[52];
vector <char> v;

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;

        v.push_back(a[0]);
        if(a[0] == ')'){
            cout << "NO" << endl;
            return 0;
        }

        for(int j=1; j<strlen(a); j++){
            v.push_back(a[j]);
            int e = v.size();
            //printf("%d\n",e);

            if(v[e-2] == '(' && v[e-1] == ')' && e-2 >=0){
                v.pop_back();
                v.pop_back();
            }
        }

        for(int i=0; i<v.size(); i++){
            printf("%c\n", v[i]);
        }

        if(v.empty())
            cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }

        for(int z=0; z<52; z++){
            a[z] = NULL;
        }

        v.clear();
    }

    return 0;
}
