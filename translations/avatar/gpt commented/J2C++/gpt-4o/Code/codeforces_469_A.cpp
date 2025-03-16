#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // Read the number of players (n) and the number of levels (levels)
    int n, levels;
    cin >> n >> levels;

    // Create a set to store the levels completed by both players
    unordered_set<int> completedLevels;

    // Read the levels completed by the first player
    for (int i = 0; i < levels; i++) {
        int level;
        cin >> level;
        completedLevels.insert(level);
    }

    // Read the number of additional levels completed by the second player
    int level2;
    cin >> level2;

    // Read the levels completed by the second player and add them to the set
    for (int i = 0; i < level2; i++) {
        int level;
        cin >> level;
        completedLevels.insert(level);
    }

    // Check if all levels from 1 to n are completed
    if (completedLevels.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}

// <END-OF-CODE>
