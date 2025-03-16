// C++:
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <cmath>
// #include <set>
// #include <iomanip>
// #include <vector>
// using namespace std;

// Define long long type for convenience
// typedef long long ll;

// Direction vectors for 4 possible movements (right, down, left, up)
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

// Define constants for maximum vertices and modulo value
// #define MAX_V 100001
// #define MOD 1000000007

// Define a type for a graph represented as an adjacency list
// typedef vector<vector<int>> Graph;

// int main() {
//     // Read the number of vertices (or nodes)
//     int n;
//     cin >> n;

//     // Initialize a vector to store the count of edges for each vertex
//     vector<int> ans(n);

//     // Read n-1 edges and count the occurrences for each vertex
//     for (int i = 0; i < n - 1; i++) {
//         int a;
//         cin >> a; // Read the vertex index
//         a--; // Convert to 0-based index
//         ans[a]++; // Increment the count for the corresponding vertex
//     }

//     // Output the count of edges for each vertex
//     for (int i = 0; i < n; i++) {
//         cout << ans[i] << endl; // Print the count for vertex i
//     }
// }

// 