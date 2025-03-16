#include <iostream>
#include <vector>

using namespace std;

// Step 2: Define global variables
// G is a vector of vectors representing the graph.
vector<int> G[100000];
// used is a boolean array to keep track of visited nodes.
bool used[100000];
// grundy is an array to store the Grundy number of each node.
int grundy[100000];

// Step 3: Define the dfs function
// The function dfs is used to perform a depth-first search on the graph.
void dfs(int v){
    // It marks the current node as visited.
    used[v] = true;
    // It initializes the Grundy number of the current node to 0.
    grundy[v] = 0;
    // It iterates through all the neighbors of the current node.
    for(int i = 0; i < G[v].size(); i++){
        // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if(!used[G[v][i]]){
            dfs(G[v][i]);
            // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
            grundy[v] ^= (grundy[G[v][i]]+1);
        }
    }
}

// Step 4: Main function
int main(){
    // It reads the number of nodes N.
    int N;
    cin >> N;
    // It reads the edges of the graph and constructs the adjacency list.
    for(int i = 0; i < N-1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    // It calls the dfs function starting from node 0.
    dfs(0);
    // It checks the Grundy number of the root node (node 0).
    if(grundy[0] != 0){
        // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
}
