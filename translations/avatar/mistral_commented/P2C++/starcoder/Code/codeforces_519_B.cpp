#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Take the number of test cases as input
    int n;
    cin >> n;

    // Read the first list 'a' of numbers from the standard input
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // Read the second list 'b' of numbers from the standard input
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    // Read the third list 'c' of numbers from the standard input
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }

    // Initialize variables x, y, and z to 0
    int x = 0;
    int y = 0;
    int z = 0;

    // Iterate through each number in list 'a' and add it to the variable 'x'
    for (int i = 0; i < n; i++) {
        x += a[i];
    }

    // Iterate through each number in list 'b' and add it to the variable 'y'
    for (int i = 0; i < n; i++) {
        y += b[i];
    }

    // Iterate through each number in list 'c' and add it to the variable 'z'
    for (int i = 0; i < n; i++) {
        z += c[i];
    }

    // Print the absolute difference between 'x' and 'y'
    cout << abs(x - y) << endl;

    // Print the absolute difference between 'y' and 'z'
    cout << abs(y - z) << endl;

    return 0;
}
