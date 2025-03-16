import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CurrencyChange {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Setting up input and output streams
        // The code starts by setting up the input and output streams to be as fast as possible.

        List<Integer> m = new ArrayList<>();
        m.add(10);
        m.add(50);
        m.add(100);
        m.add(500);

        // Step 2: Initializing a list to store denominations
        // The code initializes a list `m` to store the denominations of the currency,
        // which are 10, 50, 100, and 500.

        boolean first = true;
        while (true) {
            int money = scanner.nextInt();
            if (money == 0) {
                break; // Step 3: Reading input and processing each transaction
            }

            // Step 4: Checking if it's the first transaction and outputting a newline if necessary
            if (!first) {
                System.out.println();
            }
            first = false;

            int sum = 0;
            int[] num = new int[4];
            for (int i = 0; i < 4; ++i) {
                num[i] = scanner.nextInt();
                sum += num[i] * m.get(i);
            }

            // Step 5: Calculating the total value of the currency and the change to be given
            int change = sum - money;
            for (int i = 3; i >= 0; --i) {
                if (change / m.get(i) > 0) {
                    num[i] -= change / m.get(i);
                    change %= m.get(i);
                }
            }

            // Step 6: Calculating the change and updating the number of denominations
            for (int i = 0; i < 4; ++i) {
                if (num[i] > 0) {
                    System.out.println(m.get(i) + " " + num[i]);
                }
            }

            // Step 7: Outputting the denominations and their counts for the change
        }

        // Final Comment: The code runs until the input money is zero, processing each transaction
        // to calculate and output the change based on the available denominations.

        scanner.close();
    }
}

// <END-OF-CODE>
