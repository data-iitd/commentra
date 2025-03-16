

#include <iostream> // Including the necessary libraries
#include <vector>
#include <algorithm>

using namespace std;

int n; // Declaring the number of vertices in the graph
vector<vector<pair<int, int>>> g; // Declaring a 2D vector to represent the graph
vector<int> ans; // Declaring a vector to store the answer

void dfs(int to, int color, int parents) { // Function to perform Depth First Search
 int k = 1; // Initializing the color to 1
 for (auto e : g[to]) { // Looping through each edge adjacent to the current vertex
 if (e.second == parents) continue; // Skipping the edge if it is already colored with the current color
 if (k == color) k++; // Incrementing the color if the current vertex is already colored with the same color
 ans[e.first] = k; // Storing the answer in the vector
 dfs(e.second, k, to); // Recursively calling the DFS function for the adjacent vertex
 k++; // Incrementing the color for the next vertex
 }
}

int main() {
 cin >> n; // Reading the number of vertices from the input
 g.resize(n); // Creating a vector of size 'n' to store the graph
 for (int i = 0; i < n - 1; i++) { // Looping through each edge to add it to the graph
 int a, b;
 cin >> a >> b;
 a--;
 b--;
 g[a].push_back({i, b}); // Adding the edge from vertex 'a' to 'b'
 g[b].push_back({i, a}); // Adding the edge from vertex 'b' to 'a'
 }

 ans.resize(n - 1); // Creating a vector of size 'n-1' to store the answer
 dfs(0, -1, -1); // Calling the DFS function to find the answer

 int max = 0; // Initializing the maximum answer to 0
 for (int temp : ans) { // Looping through the vector to find the maximum answer
 max = max(max, temp);
 }

 cout << max << endl; // Printing the maximum answer
 for (int c : ans) { // Printing all the answers
 cout << c << endl;
 }

 return 0; // Returning 0 to indicate successful execution
}

