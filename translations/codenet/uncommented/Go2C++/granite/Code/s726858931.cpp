
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    char buf[1000001];
    fgets(buf, 1000001, stdin);
    string s = buf;

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        bool found = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++;
    }

    cout << "None" << endl;

    return 0;
}

// ---- readfunc
void scanInit() {
    const int cap = 1000 * 1024;
    char buf[cap];
    scanf("%s", buf);
    s = buf;
}
int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}
string nextStr() {
    string s;
    cin >> s;
    return s;
}

