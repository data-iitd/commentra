import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the day of the month
        int day;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer input from the user representing the day
        day = scanner.nextInt();

        // Use a switch statement to determine the holiday based on the day
        switch (day) {
            case 25:
                // If the day is 25, print "Christmas"
                System.out.println("Christmas");
                break;
            case 24:
                // If the day is 24, print "Christmas Eve"
                System.out.println("Christmas Eve");
                break;
            case 23:
                // If the day is 23, print "Christmas Eve Eve"
                System.out.println("Christmas Eve Eve");
                break;
            case 22:
                // If the day is 22, print "Christmas Eve Eve Eve"
                System.out.println("Christmas Eve Eve Eve");
                break;
            default:
                // Optional: Handle cases where the day is not a holiday
                System.out.println("No holiday");
                break;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
