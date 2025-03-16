import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Initialize a for loop that will iterate 5 times
        for (int i = 0; i < 5; i++) {
            // Declare and initialize a variable 'a' to store user input
            int a = scanner.nextInt();

            // Check if the user input is equal to zero
            if (a == 0) {
                // If user input is zero, print the current iteration number
                System.out.println(i + 1);
            }
        }

        // Close the Scanner object
        scanner.close();
    }
}
