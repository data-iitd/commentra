#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // User inputs the maximum level of the set
    int max_level;
    cin >> max_level;

    // User inputs two lists, x and y, separated by a newline
    vector<int> x;
    vector<int> y;
    int x_size, y_size;
    cin >> x_size;
    for (int i = 0; i < x_size; i++) {
        int x_item;
        cin >> x_item;
        x.push_back(x_item);
    }
    cin >> y_size;
    for (int i = 0; i < y_size; i++) {
        int y_item;
        cin >> y_item;
        y.push_back(y_item);
    }

    // Remove the first element from both lists, as they are not part of the sets
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert both lists to sets for faster set operations
    set<int> x_set(x.begin(), x.end());
    set<int> y_set(y.begin(), y.end());

    // Check if zero is present in the first set
    if (x_set.find(0)!= x_set.end()) {
        // If it is, remove it
        x_set.erase(0);
    }
    // Else, check if zero is present in the second set
    else {
        if (y_set.find(0)!= y_set.end()) {
            // If it is, remove it
            y_set.erase(0);
        }
    }

    // Combine both sets into a new set z
    set<int> z = x_set.union(y_set);

    // Check if the size of the combined set is equal to the maximum level
    if (z.size()!= max_level) {
        // If not, print an error message
        cout << "Oh, my keyboard!" << endl;
    }
    // Else, print a success message
    else {
        cout << "I become the guy." << endl;
    }

    return 0;
}

