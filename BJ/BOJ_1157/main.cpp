#include <iostream>
#include <algorithm>

using namespace std;

string a;
char word[1000001];

char small[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' ,'m' ,'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char big[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int cnt[27];
int max_ = -1000001;

int main(){
    cin >> a;
    int length = a.length();
    int total = 0;
    int num = 0;

    for(int i=0; i<length; i++){
        word[i] = a[i];
    }

    //sort(word, word + length);

    for(int i=0; i<27; i++){
        for(int j=0; j<length; j++){
            if(small[i] == word[j]){
                cnt[i]++;
            }
            if(big[i] == word[j]){
                cnt[i]++;
            }
        }
    }

    for(int i=0; i<27; i++){
        if(cnt[i] != 0){
            max_ = max(max_, cnt[i]);
        }
    }

    for(int i=0; i<27; i++){
        if(cnt[i] == max_){
            total++;
            num = i;
        }
    }

    if(total == 1)
        printf("%C\n", big[num]);
    else
        printf("?\n");


    return 0;
}
