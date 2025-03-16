#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the maximum level from user input
    int max_level;
    cin >> max_level;

    // Read the levels completed by player X and convert them to a list of integers
    vector<int> x;
    string x_levels;
    cin >> x_levels;
    for (int i = 0; i < x_levels.length(); i++) {
        x.push_back(x_levels[i] - '0');
    }

    // Read the levels completed by player Y and convert them to a list of integers
    vector<int> y;
    string y_levels;
    cin >> y_levels;
    for (int i = 0; i < y_levels.length(); i++) {
        y.push_back(y_levels[i] - '0');
    }

    // Remove the first element from both lists, which represents the count of levels
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert the lists of levels into sets to eliminate duplicates
    set<int> x_set(x.begin(), x.end());
    set<int> y_set(y.begin(), y.end());

    // Check if player X has completed level 0, if so, remove it from the set
    if (x_set.find(0) != x_set.end()) {
        x_set.erase(0);
    }
    // If player X has not completed level 0, check if player Y has, and remove it if present
    else if (y_set.find(0) != y_set.end()) {
        y_set.erase(0);
    }

    // Create a union of both sets to combine all unique levels completed by both players
    set<int> z = x_set.union(y_set);

    // Check if the number of unique levels completed matches the maximum level
    if (z.size() != max_level) {
        // If not, print a message indicating that not all levels were completed
        cout << "Oh, my keyboard!" << endl;
    } else {
        // If all levels were completed, print a success message
        cout << "I become the guy." << endl;
    }

    return 0;
}

