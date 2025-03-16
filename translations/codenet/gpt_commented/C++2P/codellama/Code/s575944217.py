#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;

// Define long long type for convenience
typedef long long ll;

// Direction vectors for 4 possible movements (right, down, left, up)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Define constants for maximum vertices and modulo value
#define MAX_V 100001
#define MOD 1000000007

// Define a type for a graph represented as an adjacency list
typedef vector<vector<int>> Graph;

int main() {
    // Read the number of vertices (or nodes)
    int n;
    cin >> n;

    # <START-OF-CODE>
    # Initialize a vector to store the count of edges for each vertex
    ans = [0] * n

    # Read n-1 edges and count the occurrences for each vertex
    for i in range(n-1):
        a = int(input()) # Read the vertex index
        a -= 1 # Convert to 0-based index
        ans[a] += 1 # Increment the count for the corresponding vertex
    # 