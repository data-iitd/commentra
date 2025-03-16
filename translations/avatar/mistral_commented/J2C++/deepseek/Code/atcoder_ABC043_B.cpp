#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream d;

    for (char c : s) {
        switch (c) {
            case '0':
                d << "0";
                break;
            case '1':
                d << "1";
                break;
            case 'B':
                if (!d.str().empty()) {
                    string temp = d.str();
                    temp.pop_back();
                    d.str(temp);
                }
                break;
        }
    }

    cout << d.str() << endl;
    return 0;
}

