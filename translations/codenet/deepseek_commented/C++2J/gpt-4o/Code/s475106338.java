import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Loop through four transactions
        for (int i = 0; i < 4; i++) {
            // Read the transaction type and number of items from standard input
            int t = scanner.nextInt();
            int n = scanner.nextInt();

            // Check the transaction type and calculate the total cost
            if (t == 1) {
                System.out.println(6000 * n); // If transaction type is 1, calculate cost for 6000 per item
            } else if (t == 2) {
                System.out.println(4000 * n); // If transaction type is 2, calculate cost for 4000 per item
            } else if (t == 3) {
                System.out.println(3000 * n); // If transaction type is 3, calculate cost for 3000 per item
            } else if (t == 4) {
                System.out.println(2000 * n); // If transaction type is 4, calculate cost for 2000 per item
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
