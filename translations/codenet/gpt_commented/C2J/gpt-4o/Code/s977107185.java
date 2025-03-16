import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        // Declare variables
        int i, j, N, tmp, count = 0;
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements to be sorted
        N = scanner.nextInt();
        int[] A = new int[100];

        // Input the elements into the array A
        for (i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Perform bubble sort on the array A
        for (i = 0; i < N - 1; i++) {
            for (j = N - 1; j > i; j--) {
                // Compare adjacent elements and swap if they are in the wrong order
                if (A[j] < A[j - 1]) {
                    tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;

                    // Increment the swap count
                    count++;
                }
            }
        }

        // Output the sorted array
        for (i = 0; i < N; i++) {
            System.out.print(A[i]);

            // Print a space between elements, but not after the last element
            if (i < N - 1) {
                System.out.print(" ");
            }
        }

        // Print a newline after the sorted array
        System.out.println();

        // Print the total number of swaps made during sorting
        System.out.println(count);

        scanner.close();
    }
}

// <END-OF-CODE>
