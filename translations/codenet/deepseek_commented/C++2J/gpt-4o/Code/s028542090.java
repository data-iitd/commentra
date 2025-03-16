import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k; // Declare an integer variable to store the number of elements
        long[] a = new long[100100]; // Declare an array to store up to 100100 elements
        long min, max; // Declare variables to store the minimum and maximum values
        
        k = scanner.nextInt(); // Read the number of elements from the standard input

        for (int i = 0; i < k; i++) {
            a[i] = scanner.nextLong(); // Read the elements of the array from the standard input
        }

        max = 3; 
        min = 2; // Initialize the maximum and minimum values

        if (a[k - 1] != 2) { // Check if the last element of the array is not 2
            System.out.println(-1); // Output -1 and terminate the program
            return;
        }

        for (int i = k - 2; i >= 0; i--) { // Iterate through the array in reverse order
            if (a[i] > max) { // Check if the current element is greater than the current maximum
                System.out.println(-1); // Output -1 and terminate the program
                return;
            } else {
                max = ((max / a[i]) + 1) * a[i] - 1; // Update the maximum value
                if (min % a[i] != 0) { // Check if min is not a multiple of the current element
                    min = ((min / a[i]) + 1) * a[i]; // Update the minimum value
                }
            }

            if (max <= min) { // Check if the maximum value is not greater than the minimum value
                System.out.println(-1); // Output -1 and terminate the program
                return;
            }
        }

        System.out.printf("%d %d\n", min, max); // Output the minimum and maximum values

        scanner.close();
    }
}

// <END-OF-CODE>
