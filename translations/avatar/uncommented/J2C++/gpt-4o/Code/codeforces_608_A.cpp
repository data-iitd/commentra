#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int max_sum = 0;

    while (n--) {
        int f, t;
        cin >> f >> t;
        max_sum = max(max_sum, f + t);
    }

    cout << max(max_sum, s) << endl;
    return 0;
}

// <END-OF-CODE>
