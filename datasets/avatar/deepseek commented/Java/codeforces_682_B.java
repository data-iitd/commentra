import java.io.*; // Importing necessary I/O classes
import java.util.*; // Importing necessary utility classes

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Creating a Scanner object for input
        PrintWriter pw = new PrintWriter(System.out); // Creating a PrintWriter object for output
        
        int n = in.nextInt(); // Reading the number of elements
        ArrayList<Integer> list = new ArrayList<>(); // Creating an ArrayList to store the elements
        
        // Reading the elements and adding them to the ArrayList
        for (int i = 0; i < n; i++) {
            list.add(in.nextInt());
        }
        
        Collections.sort(list); // Sorting the ArrayList
        
        int c = 1; // Initializing the counter variable
        
        // Iterating through the sorted list to find the smallest missing positive integer
        for (int i = 0; i < n; i++) {
            if (list.get(i) >= c) {
                c++;
            }
        }
        
        pw.println(c); // Printing the result
        pw.close(); // Closing the PrintWriter
    }
    
    // Debug method for debugging purposes
    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }
}
