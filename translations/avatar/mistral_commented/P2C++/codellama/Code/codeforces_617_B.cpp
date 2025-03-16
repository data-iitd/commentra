#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string a;
    cin >> a;

    if (a.find('1') == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    int product_of_zeros = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
            int count = 0;
            while (a[i + count] == '0') {
                count++;
            }
            product_of_zeros *= count + 1;
        }
    }

    cout << product_of_zeros << endl;

    return 0;
}

