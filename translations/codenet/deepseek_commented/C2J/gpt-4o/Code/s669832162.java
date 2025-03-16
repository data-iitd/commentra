import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int m1 = scanner.nextInt(); // Read the first month
        int d1 = scanner.nextInt(); // Read the first day (not used in logic)
        int m2 = scanner.nextInt(); // Read the second month
        int d2 = scanner.nextInt(); // Read the second day (not used in logic)

        if (m1 != m2) {
            System.out.println("1"); // If m1 and m2 are not equal, print 1
        } else {
            System.out.println("0"); // If m1 and m2 are equal, print 0
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
