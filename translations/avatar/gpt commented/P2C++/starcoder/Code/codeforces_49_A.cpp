#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] =='' || a[i] == '?') {
            continue;
        } else {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'Y') {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            break;
        }
    }
    return 0;
}
