import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in); 
        
        // Read the number of elements (n) and the threshold (k)
        int n = in.nextInt(), k = in.nextInt(), l = 0, c = 1; 
        
        // Loop through each element to count consecutive occurrences
        for (int i = 0; i < n; i++) { 
            // Read the next integer from input
            int a = in.nextInt(); 
            
            // Check if the current number is the same as the last one
            if (a == l) 
                c += 1; // Increment the count of consecutive occurrences
            else 
                c = 1; // Reset the count if the number changes
            
            // Update the last number to the current one
            l = a; 
        } 
        
        // Check if the count of consecutive numbers plus k exceeds n
        if (c + k > n) 
            // If true, print the number of elements that are not part of the consecutive sequence
            System.out.println(n - c); 
        else 
            // Otherwise, print -1 indicating the condition is not met
            System.out.println(-1); 
    } 
}
