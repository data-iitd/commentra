import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] A = new int[100];
        int n, t, sw = 0, mini;

        // Step 1: Reading the number of elements (n)
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Step 3: Selection Sort Implementation
        for (int i = 0; i < n; i++) {
            mini = i;
            // Find the index of the minimum element in the unsorted part of the array
            for (int j = i; j < n; j++) {
                if (A[j] < A[mini]) {
                    mini = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            t = A[i];
            A[i] = A[mini];
            A[mini] = t;
            // Increment the swap counter if a swap was made
            if (i != mini) {
                sw++;
            }
        }

        // Step 5: Printing the sorted array
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(A[i]);
        }
        System.out.println();

        // Step 6: Printing the number of swaps
        System.out.println(sw);

        scanner.close();
    }
}

// <END-OF-CODE>
