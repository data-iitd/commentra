
#include <bits/stdc++.h>

using namespace std;

// Main method is the entry point of the C++ application
int main() {
    // Create an instance of FastScanner class for reading input
    FastScanner input = FastScanner();

    int n = input.nextInt(); // Read the number of integers from the standard input

    // Initialize an empty HashMap with Integer keys and Integer values
    unordered_map<int, int> map;

    // Iterate through the given number of integers and add each integer to the HashMap with its count
    for (int i = 0; i < n; i++) {
        int val = input.nextInt(); // Read the next integer from the standard input
        map[val] = map.count(val) + 1; // Add the integer to the HashMap with its count or 1 if it's the first occurrence
    }

    // Initialize minimum value and maximum value variables
    int max = INT_MIN;
    for (auto entry : map) {
        // Update the maximum value if the current entry's value is greater than the maximum value
        int value = entry.second;
        max = max > value? max : value;
    }

    // Print the maximum value and the size of the HashMap
    cout << max << " " << map.size() << endl;

    return 0;
}

// FastScanner class for reading input efficiently
class FastScanner {
public:
    // BufferedReader for reading input
    BufferedReader br;

    // StringTokenizer for parsing input
    StringTokenizer st;

    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader with System.in as input source
    }

    String next() { // Read the next token from the input
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine()); // Create a new StringTokenizer with the next line from the input
            } catch (IOException e) {
                e.printStackTrace(); // Print the error message if an I/O error occurs
            }
        }
        return st.nextToken(); // Return the next token
    }

    int nextInt() { // Read the next integer from the input
        return Integer.parseInt(next());
    }

    long nextLong() { // Read the next long integer from the input
        return Long.parseLong(next());
    }

    double nextDouble() { // Read the next double from the input
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException { // Read the next line from the input
        return br.readLine();
    }
}

