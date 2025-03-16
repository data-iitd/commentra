import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object for input and a PrintWriter for output
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read an integer n from input
        int n = in.nextInt(); 
        
        // Calculate the square of n
        int square = n * n; 
        
        // Initialize ArrayLists to hold odd and even numbers
        ArrayList<Integer> odd = new ArrayList<>(); 
        ArrayList<Integer> even = new ArrayList<>(); 
        
        // Populate the odd and even ArrayLists with numbers from 1 to square
        for (int i = 1; i <= square; i++) { 
            if (i % 2 == 0) { 
                even.add(i); // Add to even list if the number is even
            } else { 
                odd.add(i); // Add to odd list if the number is odd
            } 
        } 
        
        // Calculate the number of loops and the division for pairing
        int loop = square / n; 
        int div = loop / 2; 
        
        // Debug output to check the value of div
        debug(div); 
        
        // Loop through the number of rows to print the pairs
        for (int i = 1; i <= loop; i++) { 
            // For each row, print div pairs of numbers
            for (int j = 0; j < div; j++) { 
                // Alternate between odd and even pairs based on the row number
                if (i % 2 == 1) { 
                    // For odd rows, print an odd number and the last even number
                    pw.print(odd.remove(0) + " " + (even.remove(even.size() - 1)) + " "); 
                } else { 
                    // For even rows, print an even number and the last odd number
                    pw.print(even.remove(0) + " " + (odd.remove(odd.size() - 1)) + " "); 
                } 
            } 
            // Move to the next line after printing pairs for the current row
            pw.println(); 
        } 
        
        // Close the PrintWriter to flush the output
        pw.close(); 
    } 
    
    // Debug method to print the contents of the passed objects
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
