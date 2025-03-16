import java.util.Scanner;

public class DateComparison {
    public static void main(String[] args) {
        // Declare variables to hold the month and day values for two dates
        int m1, d1, m2, d2;

        // Create a Scanner object to read input values for the two dates (month and day)
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for the two dates
        m1 = scanner.nextInt();
        d1 = scanner.nextInt();
        m2 = scanner.nextInt();
        d2 = scanner.nextInt();

        // Compare the months of the two dates
        if (m1 != m2) 
            // If the months are different, print "1"
            System.out.println("1");
        else 
            // If the months are the same, print "0"
            System.out.println("0");

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
