
#include <iostream>
#include <cctype>

int main(){
    int i, alpha[26];
    char ch;

    for(i = 0; i < 26; i++)alpha[i] = 0;

    while(1){
        ch = std::cin.get();
        if(std::cin.eof())break;

        if(std::isalpha(ch)){
            if(std::isupper(ch))alpha[ch - 65]++;
            else alpha[ch - 97]++;
        }
    }

    ch = 'a';
    for(i = 0; i < 26; i++, ch++){
        std::cout << ch << " : " << alpha[i] << std::endl;
    }
}
