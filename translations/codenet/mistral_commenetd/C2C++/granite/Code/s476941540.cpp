
#include <iostream>
#include <cctype>

using namespace std;

int main(){
    int i;
    int alpha[26];
    char ch;

    for(i = 0; i < 26; i++)alpha[i] = 0;

    while(1){
        ch = cin.get();

        if(ch == EOF)break;

        if(isalpha(ch)){
            if(isupper(ch))alpha[ch - 65]++;
            else alpha[ch - 97]++;
        }
    }

    ch = 'a';

    for(i = 0; i < 26; i++, ch++){
        cout << ch << " : " << alpha[i] << endl;
    }
}

