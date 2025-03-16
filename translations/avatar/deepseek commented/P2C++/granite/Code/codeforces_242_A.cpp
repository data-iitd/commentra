

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    // Taking input values for x, y, a, and b
    vector<pair<int, int>> games;
    // Initializing an empty vector called games
    for (int i = a; i <= x; i++) {
        // Looping from a to x
        if (i <= b) continue;
        // Skipping values of i that are less than or equal to b
        else {
            for (int j = b; j <= y; j++) {
                // Looping from b to y
                if (i > j) {
                    // Checking if i is greater than j
                    games.push_back(make_pair(i, j));
                    // Appending the tuple (i, j) to the games vector
                }
            }
        }
    }
    cout << games.size() << endl;
    // Printing the length of the games vector
    for (auto game : games) {
        cout << game.first << " " << game.second << endl;
        // Printing each tuple in the games vector
    }
    return 0;
}
// Printing each tuple in the games vector

