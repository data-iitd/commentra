import java.util.*; // Importing utility classes for input and output
import java.io.*; // Importing classes for input and output operations

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Reading an integer input from the user
        int x = Integer.parseInt(scan.next());
        
        // Using a ternary operator to determine the boolean value based on the input
        boolean bool = x == 1 ? true : false;
        
        // Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
        int result = !bool ? 1 : 0;
        
        // Creating a PrintWriter object to output the result to the console
        PrintWriter out = new PrintWriter(System.out);
        
        // Printing the result to the console
        out.println(result);
        
        // Flushing the output stream to ensure all data is written out
        out.flush();
    }
}
