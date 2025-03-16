import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the vector
        int N = scanner.nextInt();

        // Initialize an array of size N with integers
        long[] A = new long[N];
        for (int i = 0; i < N; i++) { // Iterate through each element in the array and read its value
            A[i] = scanner.nextLong();
        }

        // Initialize the answer variable to 0
        long answer = 0;

        // Outer loop iterates through each element in the array except the last one
        for (int i = 0; i < N - 1; i++) {
            // Inner loop iterates through the remaining elements in the array starting from the next element
            for (int j = i + 1; j < N; j++) {
                // Calculate the absolute difference between the current and next elements
                long diff = Math.abs(A[i] - A[j]);

                // Update the answer variable with the maximum difference found so far
                answer = Math.max(answer, diff);
            }
        }

        // Print the answer
        System.out.println(answer);

        scanner.close();
    }
}

// <END-OF-CODE>
