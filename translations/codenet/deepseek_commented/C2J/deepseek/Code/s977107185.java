public class BubbleSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt(); // Read the size of the array
        int[] A = new int[100]; // Declare the array with a maximum size of 100
        int i, j, tmp, count = 0; // Declare variables for loop indices, array elements, temporary variable for swapping, and swap counter

        for(i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read the elements of the array
        }

        // Implement Bubble Sort
        for(i = 0; i < N - 1; i++) {
            for(j = N - 1; j > i; j--) {
                if(A[j] < A[j - 1]) {
                    tmp = A[j]; // Swap A[j] and A[j-1]
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                    count++; // Increment the swap counter
                }
            }
        }

        for(i = 0; i < N; i++) {
            System.out.print(A[i]); // Print the sorted array elements
            if(i < N - 1) System.out.print(" "); // Print a space between elements, but not after the last element
        }

        System.out.println(); // Print a newline character to end the line

        System.out.println(count); // Print the number of swaps
    }
}
