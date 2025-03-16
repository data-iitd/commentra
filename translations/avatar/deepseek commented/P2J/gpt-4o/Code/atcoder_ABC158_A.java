import java.util.Scanner;  // Import the Scanner class for taking input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        String stdin = scanner.nextLine();  // Take input from the user and store it in the variable stdin
        String s = stdin;  // Assign the input to the variable s

        // Check if the string s contains both "A" and "B"
        String result;
        if (s.contains("A") && s.contains("B")) {
            result = "Yes";  // If both "A" and "B" are in the string, set result to "Yes"
        } else {
            result = "No";  // Otherwise, set result to "No"
        }

        System.out.println(result);  // Print the result
        scanner.close();  // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
