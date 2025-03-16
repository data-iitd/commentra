
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Define a constant number for modulo operations
    int num = 998244353; 

    // Initialize BufferedReader to read input from standard input
    BufferedReader bf(cin.rdbuf()); 

    // Initialize PrintWriter to output results to standard output
    PrintWriter out(cout.rdbuf()); 

    // Read the number of pairs (n) from input
    int n; 
    cin >> n; 

    // Create two vectors to store the two sets of integers
    vector<int> a, b; 

    // Read n pairs of integers from input
    for (int i = 0; i < n; i++) { 
        int x, y; 
        cin >> x >> y; 
        // Add the first integer of the pair to the first vector
        a.push_back(x); 
        // Add the second integer of the pair to the second vector
        b.push_back(y); 
    } 

    // Sort both vectors to prepare for median calculation
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 

    // Check if the number of elements is odd
    if (n % 2 == 1) { 
        // Calculate the result for odd n using the median values
        out << b[b.size() / 2] - a[a.size() / 2] + 1 << endl; 
    } else { 
        // Calculate the average of the two middle values for even n
        double b = (a[a.size() / 2] + a[a.size() / 2 - 1] + 0.0) / 2; 
        double c = (b[b.size() / 2] + b[b.size() / 2 - 1] + 0.0) / 2; 
        // Calculate the result for even n and print it
        out << (int)(2 * (c - b) + 1) << endl; 
    } 

    return 0; 
}

