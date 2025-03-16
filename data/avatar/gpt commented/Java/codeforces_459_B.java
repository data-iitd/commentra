import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the standard input stream
        Scanner in = new Scanner(System.in); 
        
        // Create a PrintWriter object to output results to the standard output stream
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the number of elements from input
        int N = in.nextInt(); 
        
        // Initialize an array to hold the input integers
        int[] A = new int[N]; 
        
        // Read N integers from input and store them in the array A
        for (int n = 0; n < N; n++) { 
            A[n] = in.nextInt(); 
        } 
        
        // Sort the array A to easily find the minimum and maximum values
        Arrays.sort(A); 
        
        // Identify the minimum and maximum values in the sorted array
        int min = A[0]; 
        int max = A[N - 1]; 
        
        // Initialize counters for occurrences of min and max values
        long mins = 0; 
        long maxs = 0; 
        
        // Count how many times the minimum and maximum values occur in the array
        for (int value : A) { 
            if (value == min) mins++; 
            if (value == max) maxs++; 
        } 
        
        // If all elements are the same (min equals max)
        if (min == max) { 
            // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
            pw.println((max - min) + " " + mins * (mins - 1) / 2); 
        } else { 
            // Calculate the difference and the product of occurrences of min and max
            pw.println((max - min) + " " + mins * maxs); 
        } 
        
        // Close the PrintWriter to flush the output
        pw.close(); 
    } 
    
    // Debugging method to print objects in a readable format
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
