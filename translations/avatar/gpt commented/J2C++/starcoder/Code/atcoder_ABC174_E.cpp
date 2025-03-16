#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);

    // Initialize InputReader for reading input and PrintWriter for output
    InputReader in = InputReader(cin);
    PrintWriter out = PrintWriter(cout);

    // Create an instance of Solution to solve the problem
    Solution sol = Solution();
    sol.solve(in, out);

    // Close the output stream
    out.close();
}

class Solution {
public:
    void solve(InputReader in, PrintWriter out) {
        // Read the number of logs and the value of k
        int n = in.nextInt(), k = in.nextInt();

        // Read the lengths of the logs into an array
        int logsLength[n];
        for (int i = 0; i < n; i++) {
            logsLength[i] = in.nextInt();
        }

        // Initialize binary search bounds
        int min = 1, max = (int) 1e9 + 1000;

        // Perform binary search to find the minimum possible length
        while (min < max) {
            int mid = (min + max) / 2;

            // Check if it's possible to cut the logs with the current mid length
            if (nei(mid, logsLength, k))
                max = mid; // If possible, search in the lower half
            else
                min = mid + 1; // Otherwise, search in the upper half
        }

        // Output the minimum length found
        out.println(min);
    }

    // Helper method to determine if logs can be cut with the given mid length
    bool nei(int mid, int logsLength[], int k) {
        for (int log : logsLength)
            k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed

        // Return true if we can make the cuts within the limit of k
        return k >= 0;
    }
};

class InputReader {
public:
    BufferedReader reader;
    StringTokenizer tokenizer;

    // Constructor to initialize the BufferedReader
    InputReader(istream &stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = NULL;
    }

    // Method to read the next token from input
    string next() {
        // Read a new line if the tokenizer is empty
        while (tokenizer == NULL ||!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    // Method to read the next integer from input
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Method to read an array of integers from input
    int[] readArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = nextInt(); // Fill the array with integers
        return a;
    }
};

