#include <iostream> // For input and output
#include <vector>   // For using vector
#include <algorithm> // For using max function

using namespace std;

class Edge { // Class to represent an edge
public:
    int id; // Storing the id of the edge
    int to; // Storing the vertex the edge connects to

    Edge(int id, int to) : id(id), to(to) {} // Constructor to initialize the edge
};

vector<vector<Edge>> g; // Declaring a 2D vector to represent the graph
vector<int> ans; // Declaring a vector to store the answer

void dfs(int to, int color, int parents) { // Function to perform Depth First Search
    int k = 1; // Initializing the color to 1
    for (Edge e : g[to]) { // Looping through each edge adjacent to the current vertex
        if (e.to == parents) continue; // Skipping the edge if it is already colored with the current color
        if (k == color) k++; // Incrementing the color if the current vertex is already colored with the same color
        ans[e.id] = k; // Storing the answer in the vector
        dfs(e.to, k, to); // Recursively calling the DFS function for the adjacent vertex
        k++; // Incrementing the color for the next vertex
    }
}

int main() {
    int n; // Declaring the number of vertices in the graph
    cin >> n; // Reading the number of vertices from the input
    g.resize(n); // Resizing the graph vector to hold n vertices

    for (int i = 0; i < n - 1; i++) { // Looping through each edge to add it to the graph
        int a, b;
        cin >> a >> b; // Reading the vertices of the edge
        a--; b--; // Converting to 0-based index
        g[a].emplace_back(i, b); // Adding the edge from vertex 'a' to 'b'
        g[b].emplace_back(i, a); // Adding the edge from vertex 'b' to 'a'
    }

    ans.resize(n - 1); // Resizing the answer vector to hold n-1 elements
    dfs(0, -1, -1); // Calling the DFS function to find the answer

    int max = 0; // Initializing the maximum answer to 0
    for (int temp : ans) { // Looping through the vector to find the maximum answer
        max = std::max(max, temp);
    }

    cout << max << endl; // Printing the maximum answer
    for (int c : ans) { // Printing all the answers
        cout << c << endl;
    }

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
