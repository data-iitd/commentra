#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Initialize FastScanner for efficient input reading
    FastScanner in = FastScanner(); 
    // Create a Scanner object for standard input
    Scanner sc = Scanner(cin); 
    // Create a PrintWriter object for output
    PrintWriter o = PrintWriter(cout); 
    
    // Read the number of pairs (n) and the minimum score (s)
    int n = sc.nextInt(); 
    int s = sc.nextInt(); 
    
    // Initialize a variable to keep track of the maximum sum of pairs
    int max = 0; 
    
    // Loop through each pair of integers
    while (n-- > 0) { 
        // Read the two integers f and t
        int f = sc.nextInt(); 
        int t = sc.nextInt(); 
        // Update max if the sum of f and t is greater than the current max
        if (max < f + t) { 
            max = f + t; 
        } 
    } 
    
    // Print the maximum value between max and s
    o.println(max > s? max : s); 
    // Close the PrintWriter
    o.close(); 
} 

// FastScanner class for efficient input handling
class FastScanner { 
    // Members
    string buffer; 
    istringstream ss; 
    
    // Constructor
    FastScanner() { 
        ss = new istringstream(); 
    } 
    
    // Get next token
    string next() { 
        if (!ss.eof()) { 
            ss >> buffer; 
        } 
        return buffer; 
    } 
    
    // Get next line
    string nextLine() { 
        string str = ""; 
        getline(cin, str); 
        return str; 
    } 
    
    // Get next byte
    byte nextByte() { 
        return (byte)nextShort(); 
    } 
    
    // Get next short
    short nextShort() { 
        return (short)nextLong(); 
    } 
    
    // Get next int
    int nextInt() { 
        return (int)nextLong(); 
    } 
    
    // Get next long
    long nextLong() { 
        string s = next(); 
        return s.empty()? 0 : stol(s); 
    } 
    
    // Get next double
    double nextDouble() { 
        return stod(next()); 
    } 
}

