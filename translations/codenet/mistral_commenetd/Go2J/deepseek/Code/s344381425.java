import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Declare three integer variables "a", "b", and "c"
        int a, b, c;

        // Read three integers from the standard input and store them in variables "a", "b", and "c"
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the condition "a < b && b < c" is true using an if statement
        if (a < b && b < c) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }

        // Close the Scanner object
        scanner.close();
    }
}

