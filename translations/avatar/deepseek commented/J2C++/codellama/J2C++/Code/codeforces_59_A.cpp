#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;
    
    int uppercase = 0;
    int lowercase = 0;
    
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (isupper(ch)) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    
    if (uppercase > lowercase) {
        cout << word.c_str() << endl;
    } else if (lowercase > uppercase) {
        cout << word.c_str() << endl;
    } else {
        cout << word.c_str() << endl;
    }
    
    return 0;
}

