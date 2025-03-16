#include <iostream>
#include <cctype>

using namespace std;

int main(){
    int i;
    int alpha[26] = {0};
    char ch;

    while(true){
        cin.get(ch);
        if(cin.eof()) break;

        if(isalpha(ch)){
            if(isupper(ch)) alpha[ch - 65]++;
            else alpha[ch - 97]++;
        }
    }

    ch = 'a';
    for(i = 0; i < 26; i++, ch++){
        cout << ch << " : " << alpha[i] << endl;
    }
}
