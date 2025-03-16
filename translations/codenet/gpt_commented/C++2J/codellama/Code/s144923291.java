
// Import required libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Define common types for loops
class llfor{
    public static void main (String[] args) throws java.lang.Exception{
        // Read height and width of the grid
        Scanner sc=new Scanner(System.in);
        long h=sc.nextLong();
        long w=sc.nextLong();

        // Initialize a temporary character array and the target string
        char t[]=new char[10];
        String s="snuke";

        // Iterate through the grid to find the target string
        for(long i=0;i<h;i++){
            for(long j=0;j<w;j++){
                // Read the current string from input
                for(int k=0;k<10;k++){
                    t[k]=sc.next().charAt(k);
                }
                // Check if the current string matches the target string
                if(s.equals(new String(t))){
                    // If found, calculate the position and print it
                    char c=(char)('A'+j); // Convert column index to character
                    System.out.println(c+(i+1)); // Output the position in the required format
                    return; // Exit the program after finding the target
                }
            }
        }

        // Return 0 to indicate successful execution
        return;
    }
}

