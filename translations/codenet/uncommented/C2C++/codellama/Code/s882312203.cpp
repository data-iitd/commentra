#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s;

    cin >> s;

    for (int j = 0; j < s.length(); j++) {
        for (int i = 0; i < s.length(); i++) {
            if ((i != j) && (s[i] == s[j])) {
                cout << "no" << endl;
                return 0;
            }
        }
    }

    cout << "yes" << endl;

    return 0;
}

