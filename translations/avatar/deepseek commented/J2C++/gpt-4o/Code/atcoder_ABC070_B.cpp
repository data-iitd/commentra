#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;
    
    // Read four integers from the input
    cin >> a >> b >> c >> d;

    // Check the values of a, b, c, and d and print the result based on the conditions
    if (c > b) {
        cout << 0 << endl;
    } else if (a > d) {
        cout << 0 << endl;
    } else if (a < c) {
        cout << min(b, d) - c << endl;
    } else {
        vector<int> l = {a, b, c, d};
        sort(l.begin(), l.end());
        cout << l[2] - l[1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
