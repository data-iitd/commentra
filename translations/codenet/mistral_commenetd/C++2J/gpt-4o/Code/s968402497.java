import java.util.Scanner; // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int tc = scanner.nextInt(); // Read the first integer
        int n = scanner.nextInt(); // Read the second integer
        int m = scanner.nextInt(); // Read the third integer
        int fl = 0; // Flag variable

        // Check if 'n' is greater than 'm' and swap them if necessary
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }

        // Iterate through each possible value of 'i' from 1 to 'm'
        for (int i = 1; i <= m; i++) {
            // Check if 'i' multiplied by 'tc' is within the range of 'n' to 'm'
            if (i * tc >= n && i * tc <= m) {
                // If so, print "OK" and set the flag 'fl' to 1
                System.out.println("OK");
                fl = 1;
                // Break out of the loop since we have found the answer
                break;
            }
        }

        // If the flag 'fl' is still 0, print "NG"
        if (fl == 0) {
            System.out.println("NG");
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
