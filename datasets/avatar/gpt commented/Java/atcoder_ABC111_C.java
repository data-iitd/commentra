import java.util.Arrays; 
import java.util.Collections; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements
        int n = Integer.parseInt(sc.next()); 
        
        // Initialize an array to store the input values
        int[] v = new int[100010]; 
        
        // Read n integers from input and store them in the array v
        for (int i = 0; i < n; i++) { 
            v[i] = Integer.parseInt(sc.next()); 
        } 
        
        // Initialize arrays to count occurrences of values at different positions
        Integer[] vo = new Integer[100010]; // Odd indexed counts
        Integer[] ve = new Integer[100010]; // Even indexed counts
        Integer[] vt = new Integer[100010]; // Total counts
        
        // Fill the count arrays with zeros
        Arrays.fill(vo, 0); 
        Arrays.fill(ve, 0); 
        Arrays.fill(vt, 0); 
        
        // Count occurrences of each number in odd and even indexed positions
        for (int i = 0; i < n; i++) { 
            vt[v[i]]++; // Increment total count for the value
            if (i % 2 == 0) { 
                ve[v[i]]++; // Increment even indexed count
            } else { 
                vo[v[i]]++; // Increment odd indexed count
            } 
        } 
        
        // Sort the count arrays in descending order
        Arrays.sort(vo, Collections.reverseOrder()); 
        Arrays.sort(ve, Collections.reverseOrder()); 
        Arrays.sort(vt, Collections.reverseOrder()); 
        
        // Initialize the answer variable
        int ans = 0; 
        
        // Determine the answer based on the counts of the most frequent elements
        if (vo[0] + ve[0] == vt[0]) { 
            // If the most frequent odd and even counts sum to the total count
            ans = Math.min(n - vo[0] - ve[1], n - vo[1] - ve[0]); 
        } else { 
            // Otherwise, calculate the answer based on the most frequent counts
            ans = n - vo[0] - ve[0]; 
        } 
        
        // Output the final answer
        System.out.println(ans); 
        
        // Close the scanner to prevent resource leaks
        sc.close(); 
    } 
}
