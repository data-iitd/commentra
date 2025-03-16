#include <iostream>
#include <string>

using namespace std;

void coutMessage(string str) {
    cout << str << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input
    string str;
    getline(cin, str);
    
    string a = "";
    for (int i = 0; i < n / 2; i++) {
        a += str[i];
    }
    
    if (str == a + a) {
        coutMessage("Yes");
    } else {
        coutMessage("No");
    }
    
    return 0;
}

// <END-OF-CODE>
