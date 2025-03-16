import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to get input from the user
        Scanner scanner = new Scanner(System.in);

        // Get two integers as input from the user, separated by a space
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Initialize a variable 'c' to store the sum of the larger numbers in each iteration
        int c = 0;

        // Loop through the given condition for 2 times
        for (int i = 0; i < 2; i++) {
            // Calculate the sum of the larger number in each iteration and add it to the variable 'c'
            c += Math.max(a, b);

            // Update the smaller number in each iteration
            if (a >= b) {
                a -= 1;
            } else {
                b -= 1;
            }
        }

        // Print the final result
        System.out.println(c);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
