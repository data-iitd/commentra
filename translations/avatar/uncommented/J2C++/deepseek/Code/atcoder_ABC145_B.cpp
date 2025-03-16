#include <iostream>
#include <string>
using namespace std;

void cout(string str) {
    cout << str << endl;
}

int main() {
    int n;
    string a = "", b = "", str;
    cin >> n;
    cin.ignore();
    getline(cin, str);
    for (int i = 0; i < n / 2; i++) {
        a += str[i];
    }
    if (str == a + a) {
        cout("Yes");
    } else {
        cout("No");
    }
    return 0;
}

