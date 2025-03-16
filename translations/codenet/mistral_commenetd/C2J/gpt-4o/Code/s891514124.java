import java.util.Scanner;

public class TimeConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int S; // Declare an integer variable named S

        // Read an integer value from the standard input
        S = scanner.nextInt();

        // Check if the value of S is less than 60
        if (S < 60) {
            // If the condition is true, print the time in the format "0:0:S"
            System.out.printf("0:0:%d%n", S);
        }
        // Else if the value of S is less than 3600 (1 hour)
        else if (S < 3600) {
            // Print the time in the format "0:M:S"
            System.out.printf("0:%d:%d%n", S / 60, S % 60);
        }
        // Else if the value of S is greater than or equal to 3600
        else {
            // Print the time in the format "H:M:S"
            System.out.printf("%d:%d:%d%n", S / 3600, (S % 3600) / 60, S % 60);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
