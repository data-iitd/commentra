
import java.io.BufferedReader; // Import BufferedReader class for reading input from console
import java.io.IOException; // Import IOException for handling input/output errors
import java.io.InputStreamReader; // Import InputStreamReader class for reading input from console
import java.util.*; // Import utility classes like ArrayList, HashMap, etc.
import java.math.*; // Import mathematical classes like BigInteger, BigDecimal, etc.

public class Main {

    public static void main(String[] args) throws IOException { // Main method to start the program
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader object to read input from console
        StringBuilder sb = new StringBuilder(); // Create a StringBuilder object to store the output string

        String a; // Declare a String variable to store the input string

        // Read the input string from the console and store it in the 'a' variable
        a = br.readLine();

        // Replace all occurrences of ',' in the 'a' string with a single space and store the result in the StringBuilder object
        sb.append(a.replace(',', ' '));

        // Print the modified string stored in the StringBuilder object to the console
        System.out.println(sb);
    }
}

