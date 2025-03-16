import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

class Main {
    public static void main (String[] args) throws IOException {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Initialize a StringBuilder to accumulate the results
        StringBuilder sb = new StringBuilder("");
        
        // Declare variables to hold the input integers and the digit count
        int a, b, digit;
        
        // Continuously read pairs of integers from input until there are no more integers
        while (sc.hasNextInt()) {
            // Read the first integer
            a = sc.nextInt();
            // Read the second integer
            b = sc.nextInt();
            
            // Calculate the number of digits in the sum of a and b
            digit = (int) Math.log10(a + b) + 1;
            
            // Append the digit count to the StringBuilder followed by a newline
            sb.append(digit);
            sb.append('\n');
        }
        
        // Print all the accumulated results at once
        System.out.print(sb);
    }
}
