#include <stdio.h> 
#include <string.h> 

int main() { 
    // Initialize input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create a Scanner object for reading input
    Scanner in = new Scanner(inputStream); 
    
    // Create a PrintWriter object for writing output
    PrintWriter out = new PrintWriter(outputStream); 
    
    // Create an instance of the BABC class to solve the problem
    BABC solver = new BABC(); 
    
    // Call the solve method with test number, input scanner, and output writer
    solver.solve(1, in, out); 
    
    // Close the output writer
    out.close(); 
} 

// Define the BABC class
class BABC { 
    public void solve(int testNumber, Scanner in, PrintWriter out) { 
        // Read the input string and replace occurrences of "BC" with "D"
        char s[1000]; 
        scanf("%s", s); 
        int len = strlen(s); 
        for (int i = 0; i < len; i++) { 
            if (s[i] == 'B' && s[i + 1] == 'C') { 
                s[i] = 'D'; 
                s[i + 1] = 'D'; 
            } 
        } 
        
        // Initialize counters for 'A' and the result
        long cnt = 0; 
        long tmp = 0; 
        
        // Iterate through the modified string to count occurrences
        for (int i = 0; i < len; i++) { 
            // Increment temporary counter for 'A'
            if (s[i] == 'A') { 
                tmp++; 
            } 
            // Add the count of 'A's to the result when 'D' is encountered
            else if (s[i] == 'D') { 
                cnt += tmp; 
            } 
            // Reset the temporary counter for any other character
            else { 
                tmp = 0; 
            } 
        } 
        
        // Output the final count of valid pairs
        printf("%ld\n", cnt); 
    } 
} 

