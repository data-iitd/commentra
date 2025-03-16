#include <algorithm> // For using algorithms like sort, etc.
#include <iostream>  // For input and output operations
#include <queue>     // For using the queue data structure
#include <cmath>     // For mathematical functions
#include <set>       // For using the set data structure
#include <iomanip>   // For setting precision
#include <vector>    // For using the vector container
using namespace std;
typedef long long ll; // Define a type alias for long long integers

int dx[] = {0, 1, 0, -1}; // Define an array for horizontal movement (x-axis)
int dy[] = {1, 0, -1, 0}; // Define an array for vertical movement (y-axis)
#define MAX_V 100001 // Define a constant for the maximum number of vertices
#define MOD 1000000007 // Define a constant for the modulo value
typedef vector<vector<int>> Graph; // Define a type for a graph using vector of vector of integers

int main() {
    int n;
    cin >> n; // Read the number of elements or nodes
    vector<int> ans(n); // Initialize a vector to store the count of incoming edges for each node
    for (int i = 0; i < n - 1; i++) { // Loop to read edges and populate the vector
        int a;
        cin >> a; // Read an integer
        a--; // Decrement by 1 to convert to 0-based indexing
        ans[a]++; // Increment the count of incoming edges for the node
    }
    for (int i = 0; i < n; i++) { // Loop to output the results
        cout << ans[i] << endl; // Print the number of incoming edges for each node
    }
}
