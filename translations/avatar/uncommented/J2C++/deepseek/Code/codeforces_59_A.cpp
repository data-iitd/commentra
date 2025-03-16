#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int uppercase = 0;
    int lowercase = 0;
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (isupper(ch)) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    if (uppercase > lowercase) {
        for (int i = 0; i < word.length(); i++) {
            cout << (char)toupper(word[i]);
        }
    } else if (lowercase > uppercase) {
        for (int i = 0; i < word.length(); i++) {
            cout << (char)tolower(word[i]);
        }
    } else {
        for (int i = 0; i < word.length(); i++) {
            cout << (char)tolower(word[i]);
        }
    }
    cout << endl;
    return 0;
}

