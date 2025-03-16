import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object for input and a PrintWriter for output
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the number of elements
        int n = in.nextInt(); 
        
        // Initialize an ArrayList to store the input integers
        ArrayList<Integer> list = new ArrayList<>(); 
        
        // Read n integers from input and add them to the list
        for (int i = 0; i < n; i++) { 
            list.add(in.nextInt()); 
        } 
        
        // Sort the list of integers in ascending order
        Collections.sort(list); 
        
        // Initialize a counter to track the maximum consecutive integer
        int c = 1; 
        
        // Iterate through the sorted list to find the maximum consecutive integer
        for (int i = 0; i < n; i++) { 
            // If the current integer is greater than or equal to the counter, increment the counter
            if (list.get(i) >= c) { 
                c++; 
            } 
        } 
        
        // Print the result which is the maximum consecutive integer found
        pw.println(c); 
        
        // Close the PrintWriter
        pw.close(); 
    } 
    
    // Debugging method to print objects to the error output
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
