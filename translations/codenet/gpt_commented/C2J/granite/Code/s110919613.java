
import java.util.Scanner;

public class s110919613{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Infinite loop to continuously process input until a break condition is met
        while (true) {
            // Arrays to hold digits and intermediate values
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];

            // Read the initial number and the length of digits
            int aj = sc.nextInt();
            int L = sc.nextInt();

            // Break the loop if the length L is zero
            if (L == 0) break;

            // Initialize aj with the first number and set end flag to 0
            int end = 0;
            aj = an[0];

            // Loop to process up to 20 iterations
            for (int k = 1; k < 21; k++) {
                // Extract digits of aj into a1 and a2 arrays
                int tmp = aj;
                for (int i = L - 1; i >= 0; i--) {
                    a1[i] = tmp % 10; // Store digit in a1
                    a2[i] = tmp % 10; // Store digit in a2
                    tmp /= 10;
                }

                // Sort a1 in ascending order and a2 in descending order
                for (int i = 1; i < L; i++) {
                    for (int j = 1; j < L; j++) {
                        // Ascending sort for a1
                        if (a1[j - 1] < a1[j]) {
                            int temp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = temp;
                        }
                        // Descending sort for a2
                        if (a2[j - 1] > a2[j]) {
                            int temp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = temp;
                        }
                    }
                }

                // Initialize variables for max and min calculations
                int d = 1;
                int max = 0;
                int min = 0;

                // Construct the max and min numbers from sorted digits
                for (int i = L - 1; i >= 0; i--, d *= 10) {
                    max += (a1[i] % 10) * d; // Construct max number
                    min += (a2[i] % 10) * d; // Construct min number
                }

                // Calculate the difference
                int def = max - min;

                // Check if the difference is already in the an array
                for (int i = 0; i < k; i++) {
                    if (def == an[i]) {
                        // If found, print the index, difference, and the number of iterations
                        System.out.println(i + " " + def + " " + (k - i));
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
    }
}

