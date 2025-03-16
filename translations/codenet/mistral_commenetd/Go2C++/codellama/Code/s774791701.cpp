
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int price = 700;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'o') {
            price += 100;
        }
    }
    cout << price << endl;
    return 0;
}

