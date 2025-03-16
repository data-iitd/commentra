#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read input values
    int x = nextInt(); // Target value
    int t = nextInt(); // Maximum number of steps
    int a = nextInt(); // Initial position of first entity
    int b = nextInt(); // Initial position of second entity
    int da = nextInt(); // Step size for first entity
    int db = nextInt(); // Step size for second entity
    
    int first; // Position of first entity after i steps
    int second; // Position of second entity after j steps
    bool ok = false; // Flag to indicate if the target can be reached

    // Iterate through possible steps for the first entity
    for (int i = 0; i < t; i++) { 
        first = a - (da * i); // Calculate position of first entity
        
        // Iterate through possible steps for the second entity
        for (int j = 0; j < t; j++) { 
            second = b - (db * j); // Calculate position of second entity
            
            // Check if any of the conditions to reach target x are met
            if (second + first == x || second == x || first == x || x == 0) { 
                ok = true; // Set flag to true if target is reachable
                break; // Exit inner loop if target is found
            } 
        } 
    } 
    
    // Output result based on whether the target can be reached
    if (ok) 
        out.print("YES"); // Target can be reached
    else 
        out.print("NO"); // Target cannot be reached

    return 0;
}

// Method to read the next integer from input
int nextInt() { 
    return atoi(next().c_str()); // Parse the next token as an integer
} 

// Method to read the next token from input
string next() { 
    // Continue reading until there are tokens available
    while (st == NULL ||!st.hasMoreTokens()) { 
        try { 
            st = new StringTokenizer(br.readLine()); // Read a new line and tokenize it
        } catch (IOException e) { 
            e.printStackTrace(); // Print stack trace in case of an IOException
            return "END_OF_FILE"; // Return a placeholder if an error occurs
        } 
    } 
    return st.nextToken(); // Return the next token
} 

