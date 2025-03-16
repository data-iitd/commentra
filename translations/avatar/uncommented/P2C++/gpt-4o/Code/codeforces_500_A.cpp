#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int current_cell = 1; // Start from cell 1 (1-based index)
    while (current_cell < t) {
        current_cell += s[current_cell - 1]; // Move to the next cell
        if (current_cell == t) {
            cout << "YES" << endl;
            return 0; // Exit the program
        }
    }
    cout << "NO" << endl;
    return 0;
}

// <END-OF-CODE>
