import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k; // Variable to store the number of input numbers
        long[] a = new long[100100]; // An array of size 100100 to store input numbers

        k = scanner.nextInt(); // Read the number of input numbers from the standard input

        for (int i = 0; i < k; i++) { // Iterate through each input number and read it into the array
            a[i] = scanner.nextLong();
        }

        // Check if the last number in the array is 2
        if (a[k - 1] != 2) {
            System.out.println(-1); // If not, print -1 and exit the program
            return;
        }

        // Initialize minimum and maximum values
        long max = 3, min = 2;

        // Iterate through the array from the second last number to the first number
        for (int i = k - 2; i >= 0; i--) {
            // If the current number is greater than the maximum value, print -1 and exit the program
            if (a[i] > max) {
                System.out.println(-1);
                return;
            } else {
                // Update the maximum value based on the current number
                max = ((max / a[i]) + 1) * a[i] - 1;

                // If the current number does not divide the minimum value evenly, update the minimum value
                if (min % a[i] != 0) {
                    min = ((min / a[i]) + 1) * a[i];
                }
            }

            // Check if the minimum value is less than or equal to the maximum value
            if (max <= min) {
                System.out.println(-1); // If so, print -1 and exit the program
                return;
            }
        }

        // Print the minimum and maximum values
        System.out.printf("%d %d\n", min, max);

        scanner.close();
    }
}

// <END-OF-CODE>
