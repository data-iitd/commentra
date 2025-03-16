// Importing necessary Java libraries
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

// Main method is the entry point of the Java application
public class Main {
    // Main method to start the execution of the Java program
    public static void main(String[] args) {
        try {
            // Creating a BufferedReader object to read input from the console
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

            // Reading a line of input from the console and splitting it into an array of strings using space as delimiter
            String[] x = bf.readLine().trim().split(" ");

            // Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
            int a = Integer.parseInt(x[0]);
            int b = Integer.parseInt(x[1]);

            // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
            int c = a - b * 2;

            // If the value of 'c' is negative, set it to zero
            if (c < 0) {
                c = 0;
            }

            // Print the value of 'c' to the console
            System.out.println(c);
        } catch (Exception e) {
            // Handling any exceptions that might occur during the execution of the program
        }
    }
}
