import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

class Main {
    public static void main (String[] args) throws IOException { // 1. Imports and Class Definition
        Scanner sc = new Scanner(System.in); // 2. Main Method: Initialize Scanner for input
        StringBuilder sb = new StringBuilder(""); // 2. Main Method: Initialize StringBuilder for efficient string manipulation
        int a, b, digit; // 2. Main Method: Declare variables for input and digit calculation
        while (sc.hasNextInt()) { // 3. Input Loop: Read pairs of integers until no more input
            a = sc.nextInt(); // 3. Input Loop: Read integer a
            b = sc.nextInt(); // 3. Input Loop: Read integer b
            digit = (int) Math.log10(a+b) + 1; // 4. Digit Calculation: Calculate the number of digits in the sum of a and b
            sb.append(digit); // 5. Output Construction: Append the digit count to the StringBuilder
            sb.append('\n'); // 5. Output Construction: Append a newline character
        }
        System.out.print(sb); // 6. Output: Print the StringBuilder content to the standard output
    }
}
