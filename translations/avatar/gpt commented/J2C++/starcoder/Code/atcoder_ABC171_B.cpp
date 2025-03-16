#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Create an InputReader to read input from the input stream
    InputReader in = new InputReader(cin);

    // Create a PrintWriter to write output to the output stream
    PrintWriter out = new PrintWriter(cout);

    // Create an instance of the Solution class to solve the problem
    Solution sol = new Solution();

    // Call the solve method to process the input and produce output
    sol.solve(in, out);

    // Close the PrintWriter to flush the output
    out.close();
}

class Solution {
public:
    void solve(InputReader in, PrintWriter out) {
        // Read the number of elements (n) and the number of smallest elements to sum (k)
        int n = in.ni(), k = in.ni();

        // Initialize an array to hold the input numbers
        int a[n];

        // Read n integers from input and store them in the array
        for (int i = 0; i < n; ++i)
            a[i] = in.ni();

        // Sort the array in parallel to arrange numbers in ascending order
        sort(a.begin(), a.end());

        // Initialize a variable to hold the sum of the smallest k elements
        int ans = 0;

        // Sum the first k elements of the sorted array
        for (int i = 0; i < k; ++i)
            ans += a[i];

        // Output the result (sum of the smallest k elements)
        out.println(ans);
    }
};

class InputReader {
public:
    BufferedReader reader;
    StringTokenizer tokenizer;

    // Constructor to initialize the InputReader with an InputStream
    InputReader(istream &stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    // Method to read the next token as a String
    string n() {
        // Read a new line if the tokenizer is null or has no more tokens
        while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    // Method to read the next token as an integer
    int ni() {
        return Integer.parseInt(n());
    }
};

