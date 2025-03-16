#include <bits/stdc++.h>
using namespace std;

// g is a static array of vectors that will store the graph's adjacency list representation.
vector<int> g[100001];

// maxMatching method calculates the maximum matching in a tree structure.
int maxMatching(int v, int p) {
    int a = 0; // Number of matched pairs
    int o = 0; // Number of unmatched nodes
    for (int w : g[v]) {
        if (w == p) continue; // Skip the parent node
        int r = maxMatching(w, v); // Recursively calculate matching for child nodes
        a += r / 2; // Add half of the matches from the child
        o += r % 2; // Count the unmatched nodes
    }
    return 2 * a + min(1, o) + 1; // Return the total number of matches
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Create a scanner object to read input
    MyScanner sc;
    // Create an output stream to print the result
    ofstream out("output.txt");
    int n = sc.nextInt(); // Read the number of nodes
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a = sc.nextInt() - 1; // Read node a and convert to 0-based index
        int b = sc.nextInt() - 1; // Read node b and convert to 0-based index
        g[a].push_back(b); // Add edge from a to b
        g[b].push_back(a); // Add edge from b to a
    }
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    out << (2 * m == n? "Second" : "First") << "\n"; // Determine the winner and print the result
    out.close(); // Close the output stream
    return 0;
}

// MyScanner class reads input from the standard input stream.
class MyScanner {
public:
    MyScanner() {
        cin.tie(NULL);
        cout.tie(NULL);
        // Create a stream to read input from the standard input stream
        streambuf* cinbuf = cin.rdbuf();
        // Create a stream to write input to the standard output stream
        streambuf* coutbuf = cout.rdbuf();
        // Use a stream buffer that reads from the standard input stream and writes to the standard output stream
        cin.rdbuf(coutbuf);
        // Use a stream buffer that reads from the standard output stream and writes to the standard input stream
        cout.rdbuf(cinbuf);
    }

    int nextInt() {
        return cin.get();
    }

private:
    cin.tie(NULL);
    cout.tie(NULL);
    // Create a stream to read input from the standard input stream
    streambuf* cinbuf = cin.rdbuf();
    // Create a stream to write input to the standard output stream
    streambuf* coutbuf = cout.rdbuf();
    // Use a stream buffer that reads from the standard input stream and writes to the standard output stream
    cin.rdbuf(coutbuf);
    // Use a stream buffer that reads from the standard output stream and writes to the standard input stream
    cout.rdbuf(cinbuf);
}

