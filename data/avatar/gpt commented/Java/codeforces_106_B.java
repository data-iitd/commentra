import java.util.Arrays; 
import java.util.*; 
import java.io.PrintWriter; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object for input and a PrintWriter for output
        Scanner input = new Scanner(System.in); 
        PrintWriter out = new PrintWriter(System.out); 
        
        // Read the number of entries
        int n = input.nextInt(); 
        
        // Initialize a 2D array to store the input values
        int[][] vec = new int[n][4]; 
        
        // Read input values into the 2D array
        for (int i = 0; i < n; i++) { 
            vec[i][0] = input.nextInt(); // Read first value
            vec[i][1] = input.nextInt(); // Read second value
            vec[i][2] = input.nextInt(); // Read third value
            vec[i][3] = input.nextInt(); // Read price
        } 
        
        // Initialize variables to track the best option
        int ans = 500; // Default answer if no valid option is found
        int ansprice = 20000; // Set a high initial price
        
        // Iterate through each entry to find the best option
        for (int i = 0; i < n; i++) { 
            int fl = 1; // Flag to check if the current entry is not dominated
            
            // Check if the current entry is dominated by any other entry
            for (int j = 0; j < n; j++) { 
                if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) { 
                    fl = 0; // Set flag to 0 if dominated
                } 
            } 
            
            // If the current entry is not dominated, check its price
            if (fl == 1) { 
                if (vec[i][3] < ansprice) { 
                    ansprice = vec[i][3]; // Update the best price found
                    ans = i + 1; // Update the answer with the current index (1-based)
                } 
            } 
        } 
        
        // Output the result
        System.out.println(ans); 
        out.close(); // Close the PrintWriter
    } 
}
