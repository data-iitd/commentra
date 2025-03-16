#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    size_t dotIndex = str.find('.');
    
    if (str[dotIndex - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (dotIndex + 1 < str.length() && (str[dotIndex + 1] - '0') > 4) {
        string _str = str.substr(0, dotIndex);
        cout << stoll(_str) + 1 << endl;
    } else {
        cout << str.substr(0, dotIndex) << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
