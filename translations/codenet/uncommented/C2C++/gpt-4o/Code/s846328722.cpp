#include <iostream>
#include <vector>

using namespace std;

int linersearch(const vector<int>& a, int n, int key) {
    int i = 0;
    vector<int> temp = a; // Create a copy of the array

    temp.push_back(key); // Add the key to the end of the array

    while (temp[i] != key) {
        i++;
    }
    return i != n; // Return true if the key was found in the original array
}

int main() {
    int n, q, t, count = 0;

    cin >> n;
    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> t;
        if (linersearch(s, n, t)) count++;
    }
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
