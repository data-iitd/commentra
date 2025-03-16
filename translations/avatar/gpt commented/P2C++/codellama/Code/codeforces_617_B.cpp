#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string a;
    cin >> a;
    if (a.find('1') == string::npos) {
        cout << 0;
    } else {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                count++;
            }
        }
        int product = 1;
        for (int i = 0; i < count; i++) {
            int j = 0;
            while (a[j] == '0') {
                j++;
            }
            while (a[j] == '1') {
                j++;
            }
            product *= j;
        }
        cout << product;
    }
    return 0;
}

