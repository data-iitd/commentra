import java.util.Scanner;

public class Main { 
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements (w) and the number of swaps (n) from user input
        int w = sc.nextInt();
        int n = sc.nextInt();
        
        // Initialize an array 'values' of size 'w' and populate it with integers from 1 to w
        int[] values = new int[w];
        for (int i = 0; i < values.length; i++) {
            values[i] = i + 1; // Assign values from 1 to w
        } 
        
        // Perform 'n' swaps based on user input
        for (int i = 0; i < n; i++) {
            int x = 0; // Temporary variable to hold value during swap
            String str = sc.next(); // Read the swap instruction as a string
            String[] ab = str.split(","); // Split the string to get the two indices
            
            // Parse the indices from the input string and adjust for zero-based indexing
            int a = Integer.parseInt(ab[0]) - 1;
            int b = Integer.parseInt(ab[1]) - 1;
            
            // Swap the values at indices 'a' and 'b'
            x = values[a];
            values[a] = values[b];
            values[b] = x;
        } 
        
        // Output the final state of the 'values' array after all swaps
        for(int i = 0; i < w; i++) {
            System.out.println(values[i]); // Print each value in the array
        }
    }
}
