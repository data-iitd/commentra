import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read an integer value from the standard input and store it in N
        int[] A = new int[N + 1];   // Declare an integer array named A with a size of N+1
        int[] B = new int[N];       // Declare an integer array named B with a size of N

        // Read the elements of array A from the standard input
        for (int i = 0; i < N + 1; i++) {
            A[i] = scanner.nextInt(); // Read an integer value from the standard input and store it in the ith position of array A
        }

        // Read the elements of array B from the standard input
        for (int i = 0; i < N; i++) {
            B[i] = scanner.nextInt(); // Read an integer value from the standard input and store it in the ith position of array B
        }

        long ans = 0; // Initialize a variable named ans to 0

        // Nested for loop to compare each pair of elements from arrays A and B
        for (int i = 0; i < N; i++) {
            // site i
            if (A[i] >= B[i]) {
                ans += B[i]; // Add the smaller element to the answer
                A[i] -= B[i]; // Subtract the smaller element from the corresponding element in array A
                B[i] = 0; // Set the smaller element in array B to 0
            } else {
                ans += A[i]; // Add the smaller element to the answer
                B[i] -= A[i]; // Subtract the smaller element from the corresponding element in array B
                A[i] = 0; // Set the smaller element in array A to 0
            }

            // site i + 1
            if (A[i + 1] >= B[i]) {
                ans += B[i]; // Add the smaller element to the answer
                A[i + 1] -= B[i]; // Subtract the smaller element from the corresponding element in array A
                B[i] = 0; // Set the smaller element in array B to 0
            } else {
                ans += A[i + 1]; // Add the smaller element to the answer
                B[i] -= A[i + 1]; // Subtract the smaller element from the corresponding element in array B
                A[i + 1] = 0; // Set the smaller element in array A to 0
            }
        }

        // Print the final answer
        System.out.println(ans); // Print the value of the answer variable

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
