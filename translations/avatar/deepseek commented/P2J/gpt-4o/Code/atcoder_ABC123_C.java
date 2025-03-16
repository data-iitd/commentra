import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Import necessary modules for mathematical operations, numerical computations, and data structures.

        int N = scanner.nextInt();

        // Step 2: Read an integer input N which represents some quantity or value.

        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }

        // Step 3: Read five integer inputs and store them in an array A. This array will be used to determine the minimum value among these integers.

        int minA = A[0];
        for (int i = 1; i < A.length; i++) {
            if (A[i] < minA) {
                minA = A[i];
            }
        }

        // Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result.
        int result = (int) Math.ceil((double) N / minA) + 4;

        System.out.println(result);

        // Step 4: Print the result.
        scanner.close();
    }
}

// <END-OF-CODE>
