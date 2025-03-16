import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt(); // Read the number of elements
        long[] a = new long[100100]; // Declare an array to hold the input values

        // Read the input values into the array
        for (int i = 0; i < k; i++) {
            a[i] = scanner.nextLong();
        }

        // Initialize max and min values
        long max = 3;
        long min = 2;

        // Check if the last element is not equal to 2
        if (a[k - 1] != 2) {
            System.out.println(-1); // Output -1 if the condition is met
            return; // Exit the program
        }

        // Iterate through the array from the second last element to the first
        for (int i = k - 2; i >= 0; i--) {
            // If the current element is greater than max, output -1
            if (a[i] > max) {
                System.out.println(-1); // Output -1 if the condition is met
                return; // Exit the program
            } else {
                // Update max based on the current element
                max = ((max / a[i]) + 1) * a[i] - 1;
                // Adjust min to be a multiple of the current element if necessary
                if (min % a[i] != 0) {
                    min = ((min / a[i]) + 1) * a[i];
                }
            }

            // Check if the updated max is less than or equal to min
            if (max <= min) {
                System.out.println(-1); // Output -1 if the condition is met
                return; // Exit the program
            }
        }

        // Output the final min and max values
        System.out.println(min + " " + max);
    }
}
