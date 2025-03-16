#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input for the number of elements
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];  // Take a list of integers as input
    }
    sort(l.begin(), l.end());  // Sort the list of integers

    // Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
    for (int i = 0; i < n; ++i) {
        if (find(l.begin(), l.end(), l[i] + 1) != l.end() && find(l.begin(), l.end(), l[i] + 2) != l.end()) {  // Check if i + 1 and i + 2 are in the list
            cout << "YES" << endl;  // If found, print 'YES' and break the loop
            break;
        }
    }
    if (i == n) {
        cout << "NO" << endl;  // If no such integer is found, print 'NO'
    }

    return 0;
}
