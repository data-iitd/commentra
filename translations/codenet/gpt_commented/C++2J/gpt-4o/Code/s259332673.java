import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare variables to hold the input values
        int h1, m1, h2, m2, k;

        // Read input values: start time (h1:m1), end time (h2:m2), and a duration k
        h1 = scanner.nextInt();
        m1 = scanner.nextInt();
        h2 = scanner.nextInt();
        m2 = scanner.nextInt();
        k = scanner.nextInt();

        // Calculate the total minutes from the start time to the end time
        int ans = (h2 * 60 + m2) - (h1 * 60 + m1);

        // Output the result after subtracting the duration k from the total minutes
        System.out.println(ans - k);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
