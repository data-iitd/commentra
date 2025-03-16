import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to store the input value.
        int x;

        // Create a Scanner object to read input from the user.
        Scanner scanner = new Scanner(System.in);

        // Read an integer input from the user and store it in the variable x.
        x = scanner.nextInt();

        // Check the value of x and print 1 or 0 based on the value of x.
        if (x == 0) {
            System.out.println("1");
        }
        if (x == 1) {
            System.out.println("0");
        }

        // Close the scanner to prevent resource leaks.
        scanner.close();
    }
}

// <END-OF-CODE>
