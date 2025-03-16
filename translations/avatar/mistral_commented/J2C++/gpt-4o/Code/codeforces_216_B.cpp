#include <iostream> // Including the iostream library for input and output.
#include <vector>   // Including the vector library for using dynamic arrays.
#include <list>     // Including the list library for using linked lists.
using namespace std; // Using the standard namespace.

class Main {
public:
    int count; // Declaring and initializing the count variable to 0.
    bool* seen; // Declaring and initializing the seen array to keep track of visited nodes.
    int path = 0, cycle = 1; // Declaring and initializing the path and cycle variables.
    vector<list<int>> graph; // Declaring and initializing the graph as a 2D linked list.

    int dfs(int child, int par) {
        if (seen[child]) { // Checking if the current node has already been visited.
            return cycle; // If it has, then there is a cycle in the graph and we return 1.
        }
        seen[child] = true; // Marking the current node as visited.

        for (int i : graph[child]) { // Iterating through the neighbors of the current node.
            if (i != par) { // Checking if the neighbor is not the parent node.
                this->count++; // Incrementing the count of edges traversed.
                if (dfs(i, child) == cycle) { // Recursively calling the dfs function on the neighbor.
                    return cycle; // If there is a cycle, then we return 1.
                }
            }
        }
        return path; // If there is no cycle, then we return 0.
    }
};

int main() {
    int m, n; // Declaring variables for the number of nodes and edges.
    cin >> m >> n; // Reading the number of nodes and edges from the input.
    Main ft; // Creating a new instance of the Main class.
    ft.graph.resize(m + 1); // Initializing the graph as an empty 2D linked list.
    ft.seen = new bool[m + 1](); // Initializing the seen array as a boolean array of size (m+1).

    for (int i = 0; i < n; i++) { // Reading the edges from the input and adding them to the graph.
        int x, y;
        cin >> x >> y;
        ft.graph[x].push_back(y); // Adding an edge from x to y.
        ft.graph[y].push_back(x); // Adding an edge from y to x.
    }

    int toremove = 0; // Initializing the toremove variable to 0.
    for (int i = 1; i <= m; i++) { // Iterating through all the nodes in the graph.
        if (!ft.seen[i]) { // If the current node has not been visited.
            ft.count = 0; // Resetting the count of edges traversed to 0.
            if (ft.dfs(i, 0) == ft.cycle) { // If there is a cycle in the subgraph rooted at the current node.
                if (ft.count % 2 == 1) { // If the number of edges traversed is odd.
                    toremove++; // Increment the toremove variable.
                }
            }
        }
    }

    if ((m - toremove) % 2 == 1) { // Checking if the number of nodes is odd.
        toremove++; // If it is, then increment the toremove variable.
    }

    cout << toremove << endl; // Printing the result.

    delete[] ft.seen; // Freeing the dynamically allocated memory for the seen array.
    return 0; // Returning 0 to indicate successful execution.
}

// <END-OF-CODE>
