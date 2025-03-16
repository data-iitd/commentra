
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaring static variables
    static vector<int> *g;
    static int maxMatching; // To store the maximum number of edges that can be matched in a bipartite graph

    // Function to find the maximum number of edges that can be matched in a bipartite graph
    int maxMatching(int v, int p) {
        int a = 0; // Number of edges matched from the neighboring vertices of 'v'
        int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

        // Iterating through all the neighbors of 'v'
        for (int w : g[v]) {
            if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

            // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
            int r = maxMatching(w, v);
            a += r / 2;
            o += r % 2;
        }

        // Returning the result based on the parity of 'o'
        return 2 * a + min(1, o);
    }

    int main() {
        // Creating an instance of MyScanner class for reading input
        MyScanner sc = new MyScanner();
        out = new ofstream(ios::out); // Creating an instance of ofstream for output

        // Reading the number of vertices in the graph
        int n = sc.nextInt();

        // Initializing the graph as a vector of vectors
        g = new vector<int>[n];
        for (int i = 0; i < n; ++i) g[i].clear();

        // Reading the edges and adding them to the graph
        for (int i = 0; i < n - 1; ++i) {
            int a = sc.nextInt() - 1; // Reading the first vertex of the edge
            int b = sc.nextInt() - 1; // Reading the second vertex of the edge
            g[a].push_back(b); // Adding the edge from 'a' to 'b'
            g[b].push_back(a); // Adding the edge from 'b' to 'a'
        }

        // Finding the maximum number of edges that can be matched in the graph
        maxMatching = maxMatching(0, -1) / 2;

        // Printing the result based on whether all vertices have even degree or not
        out << (2 * maxMatching == n? "Second" : "First") << endl;

        // Closing the output stream
        out.close();
    }

    class MyScanner {
    public:
        ifstream fin;
        stringstream sin;

        // Constructor for MyScanner class
        MyScanner() {
            fin.open(ios::in);
            sin.str("");
            sin.clear();
        }

        // Function to read the next token from the input stream
        string next() {
            while (sin.eof()) {
                string temp;
                getline(fin, temp);
                sin.str(temp);
                sin.clear();
            }
            return sin.str();
        }

        // Overloaded functions for reading different data types
        int nextInt() {
            return atoi(next().c_str());
        }

        long nextLong() {
            return atol(next().c_str());
        }

        double nextDouble() {
            return atof(next().c_str());
        }

        string nextLine() {
            return next();
        }
    }
}

