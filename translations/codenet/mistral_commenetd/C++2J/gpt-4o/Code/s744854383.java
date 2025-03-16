import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from the standard input
        int N = scanner.nextInt();
        
        // Allocate memory for the array and read its elements
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize variables
        int idx = 1; // Index for checking the current element in the array
        int ans = 0; // Variable to store the answer
        
        // Process the array
        for (int i = 0; i < N; i++) {
            // Check if the current element matches the index
            if (a[i] == idx) {
                // Increment the index
                idx++;
            } else {
                // Increment the answer
                ans++;
            }
        }
        
        // Output the result
        if (idx == 1) {
            System.out.println(-1); // Output -1 if all elements are the same
        } else {
            System.out.println(ans); // Output the answer otherwise
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
