
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Set up input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    // Create an InputReader to read input from the input stream
    InputReader in(cin); 

    // Create a PrintWriter to write output to the output stream
    PrintWriter out(cout); 

    // Create an instance of the Solution class to solve the problem
    Solution sol; 

    // Call the solve method to process the input and produce output
    sol.solve(in, out); 

    // Close the PrintWriter to flush the output
    out.close(); 
    return 0; 
} 

class Solution { 
public: 
    void solve(InputReader& in, PrintWriter& out) { 
        // Read the number of elements (n) and the number of smallest elements to sum (k)
        int n = in.ni(), k = in.ni(); 

        // Initialize an array to hold the input numbers
        vector<int> a(n); 

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
        out << ans << endl; 
    } 
}; 

class InputReader { 
private: 
    istream& stream; 
    stringbuf buffer; 
    istringstream tokenizer; 

public: 
    InputReader(istream& stream) : stream(stream) {} 

    string n() { 
        tokenizer.str(string()); 
        tokenizer.clear(); 
        tokenizer.str(buffer.str()); 
        buffer.str(string()); 
        string token; 
        while (tokenizer >> token) { 
            buffer << token << " "; 
        } 
        return buffer.str(); 
    } 

    int ni() { 
        int num; 
        stream >> num; 
        return num; 
    } 
}; 

