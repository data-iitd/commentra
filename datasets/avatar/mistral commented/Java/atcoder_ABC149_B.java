
import java.util.* ;  // Importing necessary Java utility classes
import java.io.* ;
import java.nio.charset.StandardCharsets ;

public class Main {
    long A, B, K; // Declaring variables A, B, and K of type long
    long x, y; // Declaring variables x and y of type long

    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8); // Creating an InputStreamReader to read from the standard input
        BufferedReader in = new BufferedReader(reader); // Creating a BufferedReader to read lines from the InputStreamReader
        Main ins = new Main(in); // Creating an instance of the Main class and passing the BufferedReader as a parameter
        ins.calc(); // Calling the calc() method to perform the calculations
        ins.showResult(); // Calling the showResult() method to display the results
        in.close(); // Closing the BufferedReader to free up resources
    }

    Main(BufferedReader in) throws IOException { // Constructor for the Main class that takes a BufferedReader as a parameter
        String[] tokens; // Declaring an array of strings named tokens

        tokens = in.readLine().split(" "); // Reading the first line of input and splitting it into tokens using the space character as a delimiter
        A = Long.parseLong(tokens[0]); // Parsing the first token into a long value and assigning it to variable A
        B = Long.parseLong(tokens[1]); // Parsing the second token into a long value and assigning it to variable B
        K = Long.parseLong(tokens[2]); // Parsing the third token into a long value and assigning it to variable K
    }

    void calc() { // Method to perform the calculations
        x = A; // Assigning the value of A to x
        y = B; // Assigning the value of B to y

        x = A - K; // Subtracting K from A and assigning the result to x

        if (x < 0) { // Checking if x is negative
            y = B + x; // If x is negative, adding the absolute value of x to B and assigning the result to y
            x = 0; // Setting x to zero
        }

        if (y < 0) { // Checking if y is negative
            y = 0; // If y is negative, setting it to zero
        }
    }

    void showResult() { // Method to display the results
        System.out.println(x + " " + y); // Printing the values of x and y separated by a space character
    }
}