// Importing necessary Java libraries for reading input from the console and handling exceptions
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

// Main method is the entry point of the Java application
public class Main {

    // Main method takes command line arguments as a String array and throws IOException exception
    public static void main(String[] args) throws IOException {

        // Creating a BufferedReader object to read input from the console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        // Reading a single line of input from the console and storing it as a String array
        String[] str = in.readLine().split(" ");

        // Parsing the first two elements of the String array as integers 'h' and 'a' respectively
        int h = Integer.parseInt(str[0]);
        int a = Integer.parseInt(str[1]);

        // Initializing a variable 'num' to keep track of the number of steps
        int num = 0;

        // Using a for loop to simulate the given condition
        for (int i = 1; h > 0; i++) {

            // Subtracting 'a' from 'h' in each iteration
            h = h - a;

            // Incrementing the 'num' variable after each successful subtraction
            num++;
        }

        // Printing the final result 'num' to the console
        System.out.println(num);
    }
}
