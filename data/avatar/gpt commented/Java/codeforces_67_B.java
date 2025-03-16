import java.io.*; 
import java.util.*; 

public class Main {
    // Constructor for the Main class, initializing the output stream
    Main() { 
        super(System.out, true); 
    } 
    
    // Scanner object for reading input
    Scanner sc = new Scanner(System.in); 
    
    public static void main(String[] $) { 
        // Create an instance of Main and call the main method
        Main o = new Main(); 
        o.main(); 
        o.flush(); 
    } 
    
    void main() { 
        // Read the number of elements (n) and the threshold (k) from input
        int n = sc.nextInt(); 
        int k = sc.nextInt(); 
        
        // Initialize an array to hold the input values
        int[] bb = new int[n]; 
        
        // Read n integers into the bb array
        for (int i = 0; i < n; i++) 
            bb[i] = sc.nextInt(); 
        
        // Initialize an array to hold the results and a counter for the results
        int[] aa = new int[n]; 
        int m = 0; 
        
        // Process the input array in reverse order
        for (int a = n - 1; a >= 0; a--) { 
            int j = 0; 
            // While there are still counts left for the current index in bb
            while (bb[a] > 0) { 
                // Check if the current index in aa is valid
                if (aa[j] >= a + k) 
                    bb[a]--; // Decrease the count for bb[a]
                j++; // Move to the next index in aa
            } 
            // Shift elements in aa to make space for the current index
            for (int j_ = m++; j_ > j; j_--) 
                aa[j_] = aa[j_ - 1]; 
            aa[j] = a; // Place the current index in aa
        } 
        
        // Output the results, incrementing by 1 for 1-based indexing
        for (int i = 0; i < n; i++) 
            print(aa[i] + 1 + " "); 
        
        println(); // Print a newline at the end
    }
}
