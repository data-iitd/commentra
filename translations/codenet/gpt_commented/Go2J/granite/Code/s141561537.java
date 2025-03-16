
import java.util.Scanner;

public class s141561537{
    public static void main(String[] args) {
        // Declare variables for the number of coins of each type and the target amount
        int a, b, c, x, sum = 0;

        // Create a Scanner object to read input values for the number of coins of each type (a, b, c) and the target amount (x)
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();

        // Use three nested loops to iterate through all possible counts of 500 yen coins, 100 yen coins, and 50 yen coins
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    // Check if the current combination of coins equals the target amount (x)
                    if (500 * i + 100 * j + 50 * k == x) {
                        // If the combination matches, increment the sum of valid combinations
                        sum++;
                    }
                }
            }
        }

        // Output the total number of combinations that sum up to the target amount
        System.out.println(sum);
    }
}
