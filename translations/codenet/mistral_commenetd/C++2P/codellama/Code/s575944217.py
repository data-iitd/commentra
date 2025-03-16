
#include <algorithm> // Header file for standard library algorithms
#include <iostream> // Header file for input and output operations
#include <queue> // Header file for queue data structure
#include <cmath> // Header file for mathematical functions
#include <set> // Header file for set data structure
#include <iomanip> // Header file for manipulating input and output streams
#include <vector> // Header file for vector data structure
using namespace std; // Using the standard namespace
typedef long long ll; // Typedef for long long integer
int dx[]={0,1,0,-1}; // Array for x-direction movement in 2D grid
int dy[]={1,0,-1,0}; // Array for y-direction movement in 2D grid
#define MAX_V 100001 // Maximum number of vertices in the graph
#define MOD 1000000007 // Modulus value for modular arithmetic

#include <iostream> // Header file for input and output operations
using namespace std; // Using the standard namespace

// Main function starts here
int main(){

    // Read the number of vertices from the input
    int n;
    cin >> n;

    // Initialize an answer vector of size n
    vector<int> ans(n);

    // Read the edges and increment the count of each vertex in the answer vector
    for(int i=0;i<n-1;i++){
        int a;
        cin >> a;
        a--; // Decrement the vertex index as it is 0-indexed
        ans[a]++; // Increment the count of the vertex
    }

    // Print the answer vector
    for(int i=0;i<n;i++)
        cout << ans[i] << endl;
}

