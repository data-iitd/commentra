#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Point { // Definition of the 'Point' class
public:
    int name; // The name of the point
    map<Point*, int> friends; // The map to store friends and their friendship lengths

    Point(int name) { // Constructor of the 'Point' class
        this->name = name;
    }

    void becomeFriend(Point* p, int length) { // Function to establish a friendship between two points
        this->friends[p] = length; // Adding the friend and their friendship length to the 'friends' map
    }
};

vector<int> colors; // Declaring a vector 'colors' to store colors of points

void dfs(Point* p, int length) { // Depth-First Search function
    if (colors[p->name] != -1) return; // Checking if the current point is already visited

    colors[p->name] = (length % 2 == 0) ? 0 : 1; // Assigning color based on the length

    for (auto& entry : p->friends) { // Iterating through the friends of the current point
        Point* friendPoint = entry.first; // Getting the friend point
        int length2 = entry.second; // Getting the length of the friendship
        dfs(friendPoint, length + length2); // Recursively calling DFS on the friend point
    }
}

int main() {
    int n;
    cin >> n; // Reading the number of points 'n'
    int m = n - 1; // Calculating the number of friendships 'm'
    colors.resize(n, -1); // Initializing the 'colors' vector with '-1' to represent unvisited points
    vector<Point*> points(n); // Creating a vector of 'Point' pointers with size 'n'

    for (int i = 0; i < n; i++) { // Initializing the 'points' vector with 'Point' objects
        points[i] = new Point(i);
    }

    while (m-- > 0) { // Reading and processing friendships between points
        int me, you, length;
        cin >> me >> you >> length; // Reading the indices and length of the friendship
        me--; you--; // Adjusting for 0-based indexing
        points[me]->becomeFriend(points[you], length); // Establishing friendship
        points[you]->becomeFriend(points[me], length); // Establishing friendship
    }

    dfs(points[0], 0); // Starting Depth-First Search from the first point

    for (int c : colors) { // Printing the colors of all points
        cout << c << endl;
    }

    // Clean up dynamically allocated memory
    for (Point* point : points) {
        delete point;
    }

    return 0;
}

// <END-OF-CODE>
