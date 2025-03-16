#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    // Read input
    int n, m;
    cin >> n >> m;

    // Initialize an empty set
    set<int> c;

    // Populate set c with differences between indices of 'S' and 'G' in each string
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        // Find the indices of 'S' and 'G' in the current string
        int index_S = s.find('S');
        int index_G = s.find('G');

        // Calculate the difference and add it to the set
        int difference = index_S - index_G;
        c.insert(difference);
    }

    // Check if there is any negative number in set c and print accordingly
    if (any_of(c.begin(), c.end(), [](int a) { return a < 0; })) {
        cout << -1 << endl;
    } else {
        cout << c.size() << endl;
    }

    return 0;
}

