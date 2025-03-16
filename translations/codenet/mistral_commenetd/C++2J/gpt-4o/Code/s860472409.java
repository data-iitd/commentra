import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int N, ans = 0, count = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the user
        N = scanner.nextInt();

        // Declare and initialize an integer array A of size N
        int[] A = new int[N];

        // Read elements of the array A from the user
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read the i-th element of array A
        }

        // Initialize variable i to 0
        int i = 0;

        // Traverse the array using a while loop
        while (i < N - 1) { // Ensure we don't go out of bounds
            // Check if the current and next elements of the array are equal
            if (A[i] == A[i + 1]) {
                // Increment the count if the current and next elements are equal
                count++;

                // If the count is odd, increment the answer
                if (count % 2 != 0) {
                    ans++;
                }
            } else {
                // Reset the count to 0 if the current and next elements are not equal
                count = 0;
            }

            // Increment the index i to move to the next element of the array
            i++;
        }

        // Print the answer
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
