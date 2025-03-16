#include <iostream>
#include <vector>

using namespace std;

bool linersearch(vector<int>& a, int n, int key) {
    int i = 0;

    // Modify the array to facilitate the search
    a.push_back(key);
    
    // Perform the linear search
    while (a[i] != key) {
        i++;
    }

    // Return true if the key is found, false otherwise
    return i != n;
}

int main() {
    int n, q, t, count = 0;

    // Read the number of elements
    cin >> n;
    vector<int> s(n);

    // Read the elements into the array s
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Read the number of queries
    cin >> q;

    // Perform a linear search for each query
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (linersearch(s, n, t)) count++;
    }

    // Print the total count of successful searches
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
