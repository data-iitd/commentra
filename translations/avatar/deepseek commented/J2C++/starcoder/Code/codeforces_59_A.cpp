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
        cout << word << endl;
    } else if (lowercase > uppercase) {
        cout << word << endl;
    } else {
        cout << word << endl;
    }
    
    return 0;
}

