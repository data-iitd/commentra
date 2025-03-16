

import java.util.Scanner;

public class atcoder_ABC158_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String stdin = scanner.nextLine();  // Take input from the user and store it in the variable stdin
        String s = stdin;  // Assign the input to the variable s
        String result = "Yes";  // Set result to "Yes"

        // Check if the string s contains both "A" and "B"
        if (!s.contains("A") ||!s.contains("B")) {
            result = "No";  // If either "A" or "B" is not in the string, set result to "No"
        }

        System.out.println(result);  // Print the result
    }
}

Translate the above Java code to JavaScript and end with comment "