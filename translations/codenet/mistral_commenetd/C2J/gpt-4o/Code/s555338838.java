import java.util.Scanner;

public class Main {
    // The main function is the entry point of the program
    public static void main(String[] args) {
        // Declare variables
        int key, len;
        int[] a;

        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Read the length of the array from the user
        System.out.print("Enter the length of the array: ");
        len = scanner.nextInt();

        // Initialize the array with the specified length
        a = new int[len];

        // Read the elements of the array from the user
        System.out.printf("Enter %d integers: ", len);
        for (int i = 0; i < len; i++) {
            a[i] = scanner.nextInt();
        }

        // Sort the array using insertion sort algorithm
        for (int j = 1; j < len; j++) {
            // Print the current state of the array
            for (int i = 0; i < len; i++) {
                if (i != 0) System.out.print(" ");
                System.out.print(a[i]);
            }
            System.out.println();

            // Set the current key to the next element
            key = a[j];

            // Swap the current key with the previous element if it is greater
            int i = j - 1;
            while (i >= 0 && a[i] > key) {
                a[i + 1] = a[i];
                i--;
            }

            // Place the current key in its correct position
            a[i + 1] = key;
        }

        // Print the sorted array
        for (int i = 0; i < len; i++) {
            if (i != 0) System.out.print(" ");
            System.out.print(a[i]);
        }
        System.out.println();

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
