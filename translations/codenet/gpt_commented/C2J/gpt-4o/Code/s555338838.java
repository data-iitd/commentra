import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        // Declare variables
        int key, i, j, len;
        int[] a = new int[101];
        
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Read the length of the array
        len = scanner.nextInt();
        
        // Read the elements of the array
        for (i = 0; i < len; i++) {
            a[i] = scanner.nextInt();
        }

        // Perform insertion sort
        for (j = 1; j < len; j++) {
            // Print the current state of the array
            for (i = 0; i < len; i++) {
                if (i != 0) {
                    System.out.print(" ");
                }
                System.out.print(a[i]);
            }
            System.out.println(); // Move to the next line after printing the array
            
            // Store the current element to be positioned
            key = a[j];
            
            // Shift elements of the sorted segment to the right
            for (i = j - 1; i >= 0 && a[i] > key; i--) {
                a[i + 1] = a[i];
            }
            
            // Place the key in its correct position
            a[i + 1] = key;
        }

        // Print the sorted array
        for (i = 0; i < len; i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(a[i]);
        }
        System.out.println(); // Move to the next line after printing the sorted array
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
