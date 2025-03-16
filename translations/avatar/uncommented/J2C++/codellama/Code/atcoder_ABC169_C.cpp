
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    long a;
    string b;
    char *bChar;
    int length;
    string bStr;
    int bInt;
    long result;

    cin >> a >> b;

    bChar = new char[b.length() + 1];
    strcpy(bChar, b.c_str());

    length = b.length();

    for (int i = 0; i < length; i++) {
        if (bChar[i] != '.') {
            bStr += bChar[i];
        }
    }

    bInt = atoi(bStr.c_str());
    result = (a * bInt) / 100;

    cout << result << endl;

    return 0;
}

