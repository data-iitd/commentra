import java.util.*;

public class BubbleSort {
    public static void main(String[] args) {
        // Read the number of elements to be sorted
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Input the elements into the array A
        int[] A = new int[N];
        for(int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Perform bubble sort on the array A
        int count = 0;
        for(int i = 0; i < N - 1; i++) {
            for(int j = N - 1; j > i; j--) {
                // Compare adjacent elements and swap if they are in the wrong order
                if(A[j] < A[j - 1]) {
                    int tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;

                    // Increment the swap count
                    count++;
                }
            }
        }

        // Output the sorted array
        for(int i = 0; i < N; i++) {
            System.out.print(A[i]);

            // Print a space between elements, but not after the last element
            if(i < N - 1) System.out.print(" ");
        }

        // Print a newline after the sorted array
        System.out.println();

        // Print the total number of swaps made during sorting
        System.out.println(count);
    }
}
