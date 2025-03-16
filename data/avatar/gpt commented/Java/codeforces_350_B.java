import java.util.*; 
import java.io.*; 

public class Main { 
    // Initialize a scanner for input
    static Scanner scanner = new Scanner(System.in); 
    
    public static void main(String[] args) { 
        // Read the number of elements
        int n = scanner.nextInt(); 
        
        // Initialize arrays to store input values and counts
        int a[] = new int[n + 1]; 
        int b[] = new int[n + 1]; 
        int num[] = new int[n + 1]; 
        
        // Read values into array a
        for (int i = 1; i <= n; i++) 
            a[i] = scanner.nextInt(); 
        
        // Read values into array b
        for (int i = 1; i <= n; i++) 
            b[i] = scanner.nextInt(); 
        
        // Count occurrences of each value in array b
        for (int i = 1; i <= n; i++) 
            num[b[i]]++; 
        
        // Initialize variables for tracking the longest sequence and its representation
        String ss = ""; 
        int ans = 0; 
        boolean st[] = new boolean[n + 1]; 
        
        // Iterate through each element to find the longest valid sequence
        for (int i = 1; i <= n; i++) { 
            // Check if the current element in a is 1
            if (a[i] == 1) { 
                st[i] = true; // Mark this index as visited
                StringBuilder sb = new StringBuilder(); 
                int x = b[i]; // Start with the corresponding value in b
                StringBuilder sss = new StringBuilder(); 
                sss.append(i); // Append the current index
                sb.append(" " + sss.reverse()); // Reverse and append to the sequence
                
                int s = 1; // Initialize the length of the current sequence
                
                // Continue to build the sequence while conditions are met
                while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) { 
                    sss = new StringBuilder(); 
                    sss.append(x); // Append the next index
                    sb.append(" " + sss.reverse()); // Reverse and append to the sequence
                    st[x] = true; // Mark this index as visited
                    x = b[x]; // Move to the next index in b
                    s++; // Increment the sequence length
                } 
                
                // Update the longest sequence found if the current one is longer
                if (s > ans) { 
                    ans = s; 
                    ss = sb.reverse().toString(); // Store the longest sequence
                } 
            } 
        } 
        
        // Output the length of the longest sequence and the sequence itself
        System.out.println(ans); 
        System.out.println(ss); 
    } 
}
