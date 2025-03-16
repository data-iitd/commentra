import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {
        // Read a line of input from the user and split it into an array of strings
        String[] s = readLine().split(" ");
        
        // Parse the first and second elements of the array as integers
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        
        // Check if b is a multiple of a
        if(b % a == 0) {
            // If true, print the sum of a and b
            System.out.println(a + b);
        } else {
            // If false, print the difference between b and a
            System.out.println(b - a);
        }
        
        // End of the main method
        return;
    }

    // Method to read a line of input from the console
    private static String readLine() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            // Return the line read from the input
            return reader.readLine();
        } catch(Exception e) {
            // In case of an exception, return the error message
            return e.getMessage();
        }
    }
}
