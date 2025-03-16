
import java.util.Scanner;

public class s663381244{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean first = true; // Flag to handle formatting of output

        while (scanner.hasNextInt()) {
            int money = scanner.nextInt();
            if (money == 0) {
                break;
            }

            // Print a newline before the output of subsequent transactions
            if (!first) {
                System.out.println();
            }
            first = false; // Set the flag to false after the first input

            int sum = 0; // Initialize sum to calculate total value of coins
            int[] num = new int[4]; // Array to hold the number of each denomination

            // Read the number of coins for each denomination and calculate the total sum
            for (int i = 0; i < 4; i++) {
                num[i] = scanner.nextInt(); // Input the number of coins for the current denomination
                sum += num[i] * (i + 1); // Update the total sum
            }

            int change = sum - money; // Calculate the change to be returned

            // Calculate how many coins of each denomination to return as change
            for (int i = 3; i >= 0; i--) {
                if (change >= (i + 1)) { // Check if the current denomination can be used for change
                    num[i] = num[i] - change / (i + 1); // Reduce the number of coins of this denomination
                    change %= (i + 1); // Update the remaining change to be returned
                }
            }

            // Output the remaining coins of each denomination that are greater than zero
            for (int i = 0; i < 4; i++) {
                if (num[i] > 0) { // Only print denominations that still have coins left
                    System.out.println((i + 1) + " " + num[i]); // Print denomination and count
                }
            }
        }
    }
}
