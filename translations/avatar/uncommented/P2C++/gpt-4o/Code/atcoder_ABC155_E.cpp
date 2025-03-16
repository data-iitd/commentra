#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    
    int pmin = 1000;
    int mmin = 0;
    s = '0' + s; // Prepend '0' to the string

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        int v = *it - '0'; // Convert char to int
        int npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        int nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }

    cout << min(pmin, mmin) << endl;

    return 0;
}

// <END-OF-CODE>
