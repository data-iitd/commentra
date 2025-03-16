
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int colors[100000]; // Declaring an integer array 'colors' to store colors of points

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

void dfs(Point* p, int length) { // Depth-First Search function
    bool alreadyKnown = colors[p->name] != -1; // Checking if the current point is already visited
    if (alreadyKnown) return; // Returning if the current point is already visited

    if (length % 2 == 0) { // Assigning color '0' to even-length friendships
        colors[p->name] = 0;
    } else { // Assigning color '1' to odd-length friendships
        colors[p->name] = 1;
    }

    for (auto entry : p->friends) { // Iterating through the friends of the current point
        Point* friend = entry.first; // Getting the friend point
        int length2 = entry.second; // Getting the length of the friendship
        dfs(friend, length + length2); // Recursively calling DFS on the friend point
    }
}

int main() {
    int n; // Declaring an integer 'n' to store the number of points
    cin >> n; // Reading the number of points 'n' from the console
    int m = n - 1; // Calculating the number of friendships 'm'
    for (int i = 0; i < n; i++) { // Initializing the 'colors' array with '-1' to represent unvisited points
        colors[i] = -1;
    }

    vector<Point*> points; // Creating a vector of 'Point' objects with size 'n'
    for (int i = 0; i < n; i++) { // Initializing the 'points' vector with 'Point' objects
        points.push_back(new Point(i));
    }

    while (m-- > 0) { // Reading and processing friendships between points
        int me, you; // Declaring integers 'me' and 'you' to store the indices of the two points
        int length; // Declaring an integer 'length' to store the length of the friendship
        cin >> me >> you >> length; // Reading the indices of the two points and the length of the friendship
        points[me]->becomeFriend(points[you], length); // Establishing friendship between 'points[me]' and 'points[you]'
        points[you]->becomeFriend(points[me], length); // Establishing friendship between 'points[you]' and 'points[me]'
    }

    dfs(points[0], 0); // Starting Depth-First Search from the first point

    for (int c : colors) { // Printing the colors of all points
        cout << c << endl;
    }

    return 0;
}

