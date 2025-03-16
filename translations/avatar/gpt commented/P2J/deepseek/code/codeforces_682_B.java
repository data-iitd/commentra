import java.util.*;
import java.io.*;

public class UniqueElements {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt(); // Number of elements in the list
        
        // Read the list of integers
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the list to facilitate counting unique elements
        Arrays.sort(l);
        
        // Initialize a variable to track unique counts
        int f = 1; // Starting count for unique elements
        
        // Initialize a counter for unique elements
        int c = 0; // Counter for unique elements
        
        // Iterate through the sorted list to count unique elements
        for (int i = 0; i < n; i++) {
            if (l[i] > c) { // Check if the current element is greater than the counter
                c += 1; // Increment the counter for unique elements
            }
        }
        
        // Output the total count of unique elements
        System.out.println(c + 1); // Print the count of unique elements (including the first element)
    }
}
