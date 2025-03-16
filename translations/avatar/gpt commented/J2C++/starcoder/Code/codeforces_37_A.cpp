#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a FastScanner object to read input efficiently
    FastScanner input = FastScanner();

    // Read the number of integers to be processed
    int n = input.nextInt();

    // Initialize a HashMap to store the frequency of each integer
    unordered_map<int, int> map;

    // Loop through the input integers and populate the frequency map
    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        // Update the count of the integer in the map
        map[val]++;
    }

    // Initialize a variable to track the maximum frequency found
    int max = INT_MIN;

    // Iterate through the entries in the frequency map to find the maximum frequency
    for (auto entry : map) {
        int value = entry.second;
        // Update max if the current frequency is greater than the current max
        max = max > value? max : value;
    }

    // Print the maximum frequency and the number of unique integers
    cout << max << " " << map.size() << endl;
}

// FastScanner class for efficient input reading
class FastScanner {
public:
    // Declare a BufferedReader object to read input efficiently
    BufferedReader br;
    // Declare a StringTokenizer object to tokenize the input
    StringTokenizer st;

    // Constructor to initialize the BufferedReader object
    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    // Method to get the next token from input
    String next() {
        // Read new line if there are no more tokens
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // Method to read the next integer from input
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Method to read the next long from input
    long nextLong() {
        return Long.parseLong(next());
    }

    // Method to read the next double from input
    double nextDouble() {
        return Double.parseDouble(next());
    }

    // Method to read the next line from input
    String nextLine() {
        String line = "";
        try {
            line = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return line;
    }
}

