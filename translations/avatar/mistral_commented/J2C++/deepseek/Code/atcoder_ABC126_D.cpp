#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

vector<int> colors; // Declaring an integer array 'colors' to store colors of points

void dfs(pair<int, int> p, int length, vector<vector<pair<int, int>>>& points) { // Depth-First Search function
    bool alreadyKnown = colors[p.first] != -1; // Checking if the current point is already visited
    if (alreadyKnown) return; // Returning if the current point is already visited

    if (length % 2 == 0) { // Assigning color '0' to even-length friendships
        colors[p.first] = 0;
    } else { // Assigning color '1' to odd-length friendships
        colors[p.first] = 1;
    }

    for (auto& neighbor : points[p.first]) { // Iterating through the neighbors of the current point
        int neighborIndex = neighbor.first; // Getting the index of the neighbor
        int length2 = neighbor.second; // Getting the length of the friendship
        dfs(make_pair(neighborIndex, p.first), length + length2, points); // Recursively calling DFS on the neighbor
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Reading the number of points 'n' and the number of friendships 'm' from the console
    colors.assign(n, -1); // Initializing the 'colors' array with '-1' to represent unvisited points
    vector<vector<pair<int, int>>> points(n); // Creating a vector of vector of pairs to store points and their friendships

    for (int i = 0; i < m; i++) { // Reading and processing friendships between points
        int me, you, length;
        cin >> me >> you >> length;
        points[me - 1].push_back(make_pair(you - 1, length)); // Establishing friendship between 'me' and 'you'
        points[you - 1].push_back(make_pair(me - 1, length)); // Establishing friendship between 'you' and 'me'
    }

    dfs(make_pair(0, -1), 0, points); // Starting Depth-First Search from the first point

    for (int c : colors) { // Printing the colors of all points
        cout << c << endl;
    }

    return 0;
}

