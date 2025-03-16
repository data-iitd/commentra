#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Create an InputReader to read input data
    InputReader in = new InputReader(cin);
    
    // Create a PrintWriter to output results
    PrintWriter out = new PrintWriter(cout);
    
    // Create an instance of TaskD to solve the problem
    TaskD solver = new TaskD();
    
    // Solve the problem for the first test case
    solver.solve(1, in, out);
    
    // Close the output stream
    out.close();
}

class TaskD {
    public:
    void solve(int testNumber, InputReader in, PrintWriter out) {
        // Read the number of elements and the modulus value
        int n = in.nextInt();
        int m = in.nextInt();
        
        // Read the array of integers
        int a[] = in.nextIntArray(n);
        
        // Initialize a HashMap to store counts of remainders
        unordered_map<int, int> dp;
        long ans = 0; // Variable to store the final answer
        int base = 0; // Variable to track the base remainder
        
        // Iterate through the array to calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the base remainder
            base = (base - a[i] % m + m) % m;
            
            // Merge the current remainder into the HashMap
            dp[base + a[i] % m]++;
            
            // Add the count of occurrences of the current base remainder to the answer
            ans += dp[base];
        }
        
        // Output the final answer
        out.println(ans);
    }
}

class InputReader {
    public:
    BufferedReader br; // BufferedReader for reading input
    StringTokenizer st; // StringTokenizer for parsing input
    
    public InputReader(istream& inputStream) {
        // Initialize BufferedReader and StringTokenizer
        br = new BufferedReader(new istreamstream(inputStream));
        st = new StringTokenizer("");
    }
    
    // Method to read the next string from input
    string nextString() {
        while (!st.hasMoreTokens()) {
            try {
                // Read the next line and tokenize it
                st = new StringTokenizer(br.readLine(), " ");
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }
        return st.nextToken();
    }
    
    // Method to read the next integer from input
    int nextInt() {
        return Integer.parseInt(nextString());
    }
    
    // Method to read an array of integers from input
    int[] nextIntArray(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }
}

