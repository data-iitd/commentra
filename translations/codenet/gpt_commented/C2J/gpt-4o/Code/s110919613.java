import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for processing
        int i, j, k, L, tmp, d, def, end, aj, max, min;

        // Create a scanner for input
        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously process input until a break condition is met
        while (true) {
            // Arrays to hold digits and intermediate values
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];

            // Read the initial number and the length of digits
            an[0] = scanner.nextInt();
            L = scanner.nextInt();

            // Break the loop if the length L is zero
            if (L == 0) break;

            // Initialize aj with the first number and set end flag to 0
            aj = an[0];
            end = 0;

            // Loop to process up to 20 iterations
            for (k = 1; k < 21; k++) {
                // Extract digits of aj into a1 and a2 arrays
                for (i = L - 1; i >= 0; i--, aj /= 10) {
                    a1[i] = aj % 10; // Store digit in a1
                    a2[i] = aj % 10; // Store digit in a2
                }

                // Sort a1 in ascending order and a2 in descending order
                for (i = 1; i < L; i++) {
                    for (j = 1; j < L; j++) {
                        // Ascending sort for a1
                        if (a1[j - 1] < a1[j]) {
                            tmp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = tmp;
                        }
                        // Descending sort for a2
                        if (a2[j - 1] > a2[j]) {
                            tmp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = tmp;
                        }
                    }
                }

                // Initialize variables for max and min calculations
                d = 1;
                max = 0;
                min = 0;

                // Construct the max and min numbers from sorted digits
                for (i = L - 1; i >= 0; i--, d *= 10) {
                    max += (a1[i] % 10) * d; // Construct max number
                    min += (a2[i] % 10) * d; // Construct min number
                }

                // Calculate the difference
                def = max - min;

                // Check if the difference is already in the an array
                for (i = 0; i < k; i++) {
                    if (def == an[i]) {
                        // If found, print the index, difference, and the number of iterations
                        System.out.printf("%d %d %d\n", i, def, k - i);
                        end = 1; // Set end flag to break the loop
                        break;
                    }
                }

                // If a match was found, exit the loop
                if (end == 1) break;

                // Store the new difference in the an array and update aj
                an[k] = def;
                aj = def;
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
