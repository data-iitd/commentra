#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    // Read the input
    string line;
    getline(cin, line);
    istringstream iss(line);
    
    int m, s, f;
    iss >> m >> s >> f;

    // Initialize the maximum time and a map to store the intervals
    int maxT = -1;
    unordered_map<int, vector<int>> map;

    // Read the intervals from the input and store them in the map
    while (m > 0) {
        getline(cin, line);
        istringstream mth(line);
        int k, start, end;
        mth >> k >> start >> end;
        map[k] = {start, end};
        maxT = max(maxT, k);
        m--;
    }

    // Initialize a string to build the sequence of actions
    string actions;

    // Determine the direction of movement and initialize the current position
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;

    // Variables to store the current interval's start and end
    int a = -1, b = -1;

    // Build the sequence of actions based on the intervals and the current position
    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t) != map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X';
        } else {
            actions += M;
            cur += d;
        }
        if (cur == f) break;
    }

    // Continue moving in the determined direction until reaching the final position
    while (cur != f) {
        actions += M;
        cur += d;
    }

    // Print the sequence of actions
    cout << actions << endl;

    return 0;
}
// <END-OF-CODE>
