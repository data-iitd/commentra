import java.util.Scanner;
// Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        int a, b, c;
        // Declare three integer variables: a, b, and c

        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the standard input

        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        // Use the Scanner object to read three integers from the standard input
        // and assign them to the variables a, b, and c respectively

        if (a < b && b < c) {
            System.out.println("Yes");
            // If the condition a < b && b < c is true, print the string "Yes"
            // followed by a newline character to the standard output
        } else {
            System.out.println("No");
            // If the condition a < b && b < c is false, print the string "No"
            // followed by a newline character to the standard output
        }

        scanner.close();
        // Close the Scanner object to free up resources
    }
}
// End of the Main class
