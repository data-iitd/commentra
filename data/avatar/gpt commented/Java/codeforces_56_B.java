import java.util.*; 
import java.io.*; 
import java.lang.Math; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in); 
        
        // Read the length of the array
        int len = scan.nextInt(); 
        
        // Initialize an array of the specified length
        int a[] = new int[len]; 
        
        // Populate the array with user input
        for (int i = 0; i < len; i++) { 
            a[i] = scan.nextInt(); 
        } 
        
        // Initialize variables to track the left and right indices of the mismatch
        int l = 0; 
        int r = 0; 
        
        // Flags to indicate the state of the search for mismatches
        boolean flag = false; 
        boolean isTrue = false; 
        
        // Loop through the array to find the first and second mismatches
        loop: 
        for (int i = 0; i < len; i++) { 
            // Check if the current element does not match its expected value
            if (a[i] != i + 1 && !flag) { 
                // Set the left index to the current position (1-based index)
                l = i + 1; 
                // Set the flag to indicate the first mismatch has been found
                flag = true; 
                continue; 
            } 
            // Check for the second mismatch
            if (a[i] != i + 1 && flag) { 
                // Set the right index to the current position (1-based index)
                r = i + 1; 
                // Check if the previous element is less than the current element
                if ((a[r - 1] - a[r - 2] > 0)) { 
                    // Set the isTrue flag to indicate a valid mismatch has been found
                    isTrue = true; 
                    break loop; 
                } 
            } 
        } 
        
        // Output the result based on whether a valid mismatch was found
        System.out.println((!isTrue) ? l + " " + r : "0" + " " + "0"); 
    } 
}
