import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Read the length of the array
        int len = scanner.nextInt();
        int[] a = new int[101];
        
        // Step 2: Read the elements of the array
        for (int i = 0; i < len; i++) {
            a[i] = scanner.nextInt();
        }

        // Step 3: Perform Insertion Sort
        for (int j = 1; j < len; j++) {
            // Print the array before each iteration
            for (int i = 0; i < len; i++) {
                System.out.print(i != 0 ? " " + a[i] : a[i]);
            }
            System.out.println();
            
            // Store the current element to be inserted
            int key = a[j];
            
            // Shift elements to the right to make space for the key
            int i;
            for (i = j - 1; i >= 0 && a[i] > key; i--) {
                a[i + 1] = a[i];
            }
            
            // Insert the key into the correct position
            a[i + 1] = key;
        }

        // Step 4: Print the sorted array
        for (int i = 0; i < len; i++) {
            System.out.print(i != 0 ? " " + a[i] : a[i]);
        }
        System.out.println();
        
        scanner.close();
    }
}

// <END-OF-CODE>
