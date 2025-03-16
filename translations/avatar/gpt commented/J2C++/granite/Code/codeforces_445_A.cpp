
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a BufferedReader to read input from the console
    BufferedReader buf = new BufferedReader(new InputStreamReader(System.in)); 

    // Read the first line of input and split it into an array of strings
    String[] inp = buf.readLine().split(""); 

    // Parse the first two elements of the input array as integers n and m
    int n = Integer.parseInt(inp[0]); 
    int m = Integer.parseInt(inp[1]); 

    // Initialize an array to hold the resulting strings
    String[] ans = new String[n]; 

    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) { 
        // Read the current line of input
        String str = buf.readLine(); 

        // Create a StringBuilder to construct the output for the current line
        StringBuilder temp = new StringBuilder(""); 

        // Loop through each character in the current line
        for (int j = 0; j < m; j++) 
            // Check if the character is a '-'
            if (str.charAt(j) == '-') 
                // Append '-' to the StringBuilder if it is
                temp.append("-"); 
            else { 
                // If the character is not '-', determine whether to append 'W' or 'B'
                if ((i + j) % 2 == 1) 
                    temp.append("W"); // Append 'W' for odd indices
                else 
                    temp.append("B"); // Append 'B' for even indices
            } 
        // Store the constructed string in the ans array
        ans[i] = temp.toString(); 
    } 

    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) { 
        cout << ans[i] << endl; 
    } 

    return 0;
}
