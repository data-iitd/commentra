
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string a;
    getline(cin, a);

    int product_of_zeros = 1;
    int count = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') {
            product_of_zeros *= count + 1;
            count = 0;
        } else {
            count++;
        }
    }

    cout << product_of_zeros << endl;

    return 0;
}

