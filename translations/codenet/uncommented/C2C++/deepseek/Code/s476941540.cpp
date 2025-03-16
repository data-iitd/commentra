#include <iostream>
#include <cctype>

int main(){
    int i;
    int alpha[26] = {0};
    char ch;

    while(true){
        std::cin >> ch;
        if(std::cin.eof())break;

        if(std::isalpha(ch)){
            if(std::isupper(ch))alpha[ch - 'A']++;
            else alpha[ch - 'a']++;
        }
    }

    ch = 'a';
    for(i = 0; i < 26; i++, ch++){
        std::cout << ch << " : " << alpha[i] << std::endl;
    }
}
