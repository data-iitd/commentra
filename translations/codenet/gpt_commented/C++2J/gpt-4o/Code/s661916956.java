import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c; // Declare three integer variables to hold the input values
        a = scanner.nextInt(); // Read the first integer from the user
        b = scanner.nextInt(); // Read the second integer from the user
        c = scanner.nextInt(); // Read the third integer from the user

        // Check if 'a' is greater than 'b', if so, swap their values
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Check if 'b' is greater than 'c', if so, swap their values
        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }

        // Check again if 'a' is greater than 'b', if so, swap their values
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Output the sorted values of a, b, and c
        System.out.println(a + " " + b + " " + c);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
