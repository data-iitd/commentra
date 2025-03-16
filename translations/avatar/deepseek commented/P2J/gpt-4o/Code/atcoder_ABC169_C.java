import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Set the recursion limit (not directly applicable in Java)
        
        // Debugging function to print debug information
        boolean debug = System.getenv("TERM_PROGRAM") != null;
        
        // Function to read input from stdin
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        try {
            // Read two inputs, convert one to integer and the other to scaled integer
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = (int) (Double.parseDouble(input[1]) * 100 + 0.1);
            
            // Perform the calculation and print the result
            System.out.println(a * b / 100);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

// <END-OF-CODE>
