import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner for input
        Scanner scanner = new Scanner(System.in);

        // Initialize a list 'm' to store the multipliers
        List<Integer> m = new ArrayList<>();
        m.add(10);
        m.add(50);
        m.add(100);
        m.add(500);

        boolean first = true; // Initialize a boolean variable 'first' to check if it's the first iteration of the loop

        // Main loop to read the input money and calculate the change
        while (scanner.hasNextInt()) {
            int money = scanner.nextInt();
            if (money == 0) break; // Exit if money is 0

            // If it's not the first iteration, print a newline character to separate the outputs
            if (!first) {
                System.out.println();
            }

            // Set 'first' to false
            first = false;

            // Initialize variables 'sum' and 'num'
            int sum = 0;
            int[] num = new int[4];

            // Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
            for (int i = 0; i < 4; i++) {
                num[i] = scanner.nextInt(); // Read the number
                sum += num[i] * m.get(i); // Calculate the product and add it to the sum
            }

            // Calculate the change
            int change = sum - money;

            // Adjust the numbers to get the exact change
            for (int i = 3; i >= 0; i--) {
                // If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
                if (change / m.get(i) > 0) {
                    num[i] -= change / m.get(i);
                    change %= m.get(i);
                }
            }

            // Print the numbers that still have a positive value
            for (int i = 0; i < 4; i++) {
                if (num[i] > 0) {
                    System.out.println(m.get(i) + " " + num[i]);
                }
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
