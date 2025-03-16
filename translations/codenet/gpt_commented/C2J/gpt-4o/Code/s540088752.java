import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the arrays from user input
        int N = scanner.nextInt();
        
        // Declare an array A of size N+1 and an array B of size N
        int[] A = new int[N + 1];
        int[] B = new int[N];
        
        // Read N+1 integers into array A from user input
        for (int i = 0; i < N + 1; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Read N integers into array B from user input
        for (int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        
        // Initialize a variable to hold the total answer
        long ans = 0;
        
        // Loop through each index of the arrays to calculate the answer
        for (int i = 0; i < N; i++) {
            // Handle the case for site i
            if (A[i] >= B[i]) {
                // If A[i] can satisfy B[i], add B[i] to the answer
                ans += B[i];
                // Decrease A[i] by B[i] and set B[i] to 0
                A[i] -= B[i];
                B[i] = 0;
            } else {
                // If A[i] cannot satisfy B[i], add A[i] to the answer
                ans += A[i];
                // Decrease B[i] by A[i] and set A[i] to 0
                B[i] -= A[i];
                A[i] = 0;
            }

            // Handle the case for site i + 1
            if (A[i + 1] >= B[i]) {
                // If A[i + 1] can satisfy B[i], add B[i] to the answer
                ans += B[i];
                // Decrease A[i + 1] by B[i] and set B[i] to 0
                A[i + 1] -= B[i];
                B[i] = 0;
            } else {
                // If A[i + 1] cannot satisfy B[i], add A[i + 1] to the answer
                ans += A[i + 1];
                // Decrease B[i] by A[i + 1] and set A[i + 1] to 0
                B[i] -= A[i + 1];
                A[i + 1] = 0;
            }
        }
        
        // Print the final answer
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
