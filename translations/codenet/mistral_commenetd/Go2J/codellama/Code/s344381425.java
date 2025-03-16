// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize three integer variables "a", "b", and "c"
        // with values read from the standard input using the Scanner class
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the condition "a < b && b < c" is true using an if statement
        if (a < b && b < c) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }

        // Return from the main function
        return;
    }
}

// End of code


Translate the above Java code to C++ and end with comment "