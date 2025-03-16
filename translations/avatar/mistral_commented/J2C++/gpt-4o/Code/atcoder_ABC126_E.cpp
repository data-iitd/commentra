#include <iostream>
#include <vector>
using namespace std;

class UnionFindTree { // Defining the UnionFindTree class
    int n; // Number of vertices
    vector<int> par; // Parent array to store the parent of each vertex
    vector<int> rank; // Rank array to store the rank of each vertex in the tree

public:
    UnionFindTree(int n) { // Constructor of UnionFindTree class
        this->n = n; // Setting the number of vertices
        par.resize(n); // Initializing the parent array
        rank.resize(n); // Initializing the rank array
        for (int i = 0; i < n; i++) { // Initializing all vertices as root
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) { // Method to find the root of a vertex
        if (par[x] == x) { // Base case: if the current vertex is the root
            return x; // Return the current vertex
        } else { // Recursive case: find the root of the parent of the current vertex
            return par[x] = find(par[x]); // Update the parent of the current vertex to be the parent of its parent
        }
    }

    void unite(int x, int y) { // Method to merge two vertices
        x = find(x); // Finding the root of vertex x
        y = find(y); // Finding the root of vertex y
        if (x == y) return; // Return if the vertices are already connected
        if (rank[x] < rank[y]) { // If the rank of y is greater, make x the parent of y
            par[x] = y;
        } else { // Otherwise, make y the parent of x and increment its rank if they have the same rank
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) { // Method to check if two vertices are connected
        return find(x) == find(y); // Return true if they have the same root
    }
};

class Main { // Defining the Main class
public:
    void doIt() { // Defining a method named doIt
        int n;
        cin >> n; // Reading the number of vertices n from the standard input
        UnionFindTree utf(n); // Creating an instance of UnionFindTree class with n vertices
        int m;
        cin >> m; // Reading the number of edges m from the standard input

        // Processing the edges
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z; // Reading the source vertex x, destination vertex y, and weight z of the edge
            utf.unite(x - 1, y - 1); // Merging the two vertices x and y (0-indexed)
        }

        int cnt = 0; // Initializing a counter variable for the number of connected components
        for (int i = 0; i < n; i++) { // Iterating through all the vertices
            if (utf.find(i) == i) { // Checking if the current vertex is the root of a connected component
                cnt++; // Incrementing the counter if it is
            }
        }
        cout << cnt << endl; // Printing the number of connected components
    }
};

int main() { // Main method to run the program
    Main().doIt(); // Calling the doIt method of Main class
    return 0;
}

// <END-OF-CODE>
