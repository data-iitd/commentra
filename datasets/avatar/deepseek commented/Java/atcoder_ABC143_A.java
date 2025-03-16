import java.io.BufferedReader; // Importing BufferedReader for input operations
import java.io.InputStreamReader; // Importing InputStreamReader to read input stream
import java.util.Scanner; // Importing Scanner for reading input (not used in this code)

public class Main { // Defining the Main class
    public static void main(String[] args) { // Main method where execution begins
        try { // Beginning of try block to handle potential exceptions
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); // Creating a BufferedReader object to read input
            String[] x = bf.readLine().trim().split(" "); // Reading input and splitting it into an array of strings
            int a = Integer.parseInt(x[0]); // Converting the first element of the array to an integer
            int b = Integer.parseInt(x[1]); // Converting the second element of the array to an integer
            int c = a - b * 2; // Performing a mathematical operation to calculate a result
            if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
            System.out.println(c); // Printing the result to the standard output
        } catch (Exception e) { // Catch block to handle exceptions
            // Handle exceptions (not implemented in this code)
        }
    }
}
