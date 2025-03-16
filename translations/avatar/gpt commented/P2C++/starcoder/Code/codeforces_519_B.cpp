#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read an integer input which represents the number of elements in the lists
    int n;
    cin >> n;

    // Read three lists of integers from input
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Initialize variables to hold the sum of each list
    int x = 0;
    int y = 0;
    int z = 0;

    // Calculate the sum of elements in list 'a'
    for (int i = 0; i < n; i++) {
        x += a[i];
    }

    // Calculate the sum of elements in list 'b'
    for (int i = 0; i < n; i++) {
        y += b[i];
    }

    // Calculate the sum of elements in list 'c'
    for (int i = 0; i < n; i++) {
        z += c[i];
    }

    // Print the absolute difference between the sums of list 'a' and list 'b'
    cout << abs(x - y) << endl;

    // Print the absolute difference between the sums of list 'b' and list 'c'
    cout << abs(y - z) << endl;

    return 0;
}

