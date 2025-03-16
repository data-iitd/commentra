
#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

int n; // Declaring the number of vertices in the graph
vector<list<pair<int, int>>> g; // Declaring a 2D vector to represent the graph
int* ans; // Declaring an array to store the answer

void dfs(int to, int color, int parents) { // Function to perform Depth First Search
    int k = 1; // Initializing the color to 1
    for (auto e : g[to]) { // Looping through each edge adjacent to the current vertex
        if (e.second == parents) continue; // Skipping the edge if it is already colored with the current color
        if (k == color) k++; // Incrementing the color if the current vertex is already colored with the same color
        ans[e.first] = k; // Storing the answer in the array
        dfs(e.second, k, to); // Recursively calling the DFS function for the adjacent vertex
        k++; // Incrementing the color for the next vertex
    }
}

int main() {
    cin >> n; // Reading the number of vertices from the input
    g = vector<list<pair<int, int>>>(n); // Creating an empty vector to store the graph
    for (int i = 0; i < n; i++) { // Looping through each vertex to create an empty vector for its adjacent edges
        g[i] = list<pair<int, int>>();
    }

    for (int i = 0; i < n - 1; i++) { // Looping through each edge to add it to the graph
        int a, b; // Declaring variables to store the vertices of the edge
        cin >> a >> b; // Reading the vertices of the edge from the input
        g[a - 1].push_back(make_pair(i, b - 1)); // Adding the edge from vertex 'a' to 'b'
        g[b - 1].push_back(make_pair(i, a - 1)); // Adding the edge from vertex 'b' to 'a'
    }

    ans = new int[n - 1]; // Creating an array of size 'n-1' to store the answer
    dfs(0, -1, -1); // Calling the DFS function to find the answer

    int max = 0; // Initializing the maximum answer to 0
    for (int temp : ans) { // Looping through the array to find the maximum answer
        max = max > temp ? max : temp;
    }

    cout << max << endl; // Printing the maximum answer
    for (int c : ans) { // Printing all the answers
        cout << c << endl;
    }

    return 0;
}

