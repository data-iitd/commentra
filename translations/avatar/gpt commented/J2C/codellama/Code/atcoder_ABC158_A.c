#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Initialize input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create a Scanner object for reading input and a PrintWriter for output
    Scanner in = new Scanner(inputStream); 
    PrintWriter out = new PrintWriter(outputStream); 
    
    // Create an instance of the AStationAndBus class to solve the problem
    AStationAndBus solver = new AStationAndBus(); 
    
    // Call the solve method with test number 1, passing the input and output objects
    solver.solve(1, in, out); 
    
    // Close the PrintWriter to flush the output
    out.close(); 
} 

// Static inner class to handle the logic of the problem
class AStationAndBus { 
    public void solve(int testNumber, Scanner in, PrintWriter out) { 
        // Read the input string
        char s[100]; 
        scanf("%s", s); 
        
        // Check if the string contains both 'A' and 'B'
        if (strstr(s, "A") && strstr(s, "B")) { 
            // If both characters are present, print "Yes"
            printf("Yes\n"); 
        } else { 
            // If either character is missing, print "No"
            printf("No\n"); 
        } 
    } 
} 

