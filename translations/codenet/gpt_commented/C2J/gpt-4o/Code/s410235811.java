import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to store user input
        Scanner scanner = new Scanner(System.in);
        int n;

        // Read an integer value from the user
        n = scanner.nextInt();

        // Check if the number is even
        if (n % 2 == 0) {
            // If the number is even, print half of the number
            System.out.println(n / 2);
        } else {
            // If the number is odd, print half of the number plus one
            System.out.println((n / 2) + 1);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
