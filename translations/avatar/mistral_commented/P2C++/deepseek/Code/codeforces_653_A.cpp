#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements in the list
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];  // Read the list of integers
    }
    sort(l.begin(), l.end());  // Sort the list in ascending order

    for (int i = 0; i < n; ++i) {  // Iterate through each element in the sorted list
        if (find(l.begin(), l.end(), l[i] + 1) != l.end() && find(l.begin(), l.end(), l[i] + 2) != l.end()) {  // Check if the next two elements are also in the list
            cout << "YES" << endl;  // If yes, print 'YES' and break out of the loop
            break;
        }
    }
    if (n == 0 || n == 1 || n == 2) {
        cout << "NO" << endl;  // If no, print 'NO' after the loop finishes
    }
    return 0;
}
