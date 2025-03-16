
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

class Main {
    public static void main (String[] args) throws IOException {
        // Initialize Scanner to read input from the console
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(""); // Initialize an empty StringBuilder to store the output

        // Loop through the input until the end of the file is reached
        while (sc.hasNextInt()) { // Check if the next token is an integer
            // Read the first integer from the input
            int a = sc.nextInt();
            // Read the second integer from the input
            int b = sc.nextInt();

            // Calculate the number of digits required to represent the sum of the two integers
            int digit = (int) Math.log10(a + b) + 1;

            // Append the calculated digit and a newline character to the StringBuilder
            sb.append(digit);
            sb.append('\n');
        }

        // Print the final output to the console
        System.out.print(sb);
    }
}