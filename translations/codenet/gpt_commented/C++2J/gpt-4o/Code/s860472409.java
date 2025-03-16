import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int N, ans = 0, count = 0;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        N = scanner.nextInt();

        // Initialize an array of size N
        int[] A = new int[N];

        // Input the elements into the array
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Loop through the array until the second last element
        for (int i = 0; i < N - 1; i++) {
            // Check if the current element is equal to the next element
            if (A[i] == A[i + 1]) {
                count++; // Increment count for consecutive elements
                
                // If count is odd, increment the answer
                if (count % 2 != 0) {
                    ans++;
                }
            } else {
                // Reset count if elements are not equal
                count = 0;
            }
        }

        // Output the final answer
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
