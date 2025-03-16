public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read the size of the arrays
        int N = scanner.nextInt();
        
        // Declare arrays A and B with sizes N+1 and N respectively
        int[] A = new int[N + 1];
        int[] B = new int[N];
        
        // Read N+1 integers into array A
        for (int i = 0; i < N + 1; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Read N integers into array B
        for (int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        
        // Initialize the result variable
        long ans = 0;
        
        // Loop through each index from 0 to N-1
        for (int i = 0; i < N; i++) {
            
            // Site i
            // Check if the current element in A is greater than or equal to the current element in B
            if (A[i] >= B[i]) {
                // Add the current element in B to ans and subtract it from A
                ans += B[i];
                A[i] -= B[i];
                // Set the current element in B to 0
                B[i] = 0;
            } else {
                // Add the current element in A to ans and subtract it from B
                ans += A[i];
                B[i] -= A[i];
                // Set the current element in A to 0
                A[i] = 0;
            }

            // Site i + 1
            // Check if the next element in A is greater than or equal to the current element in B
            if (A[i + 1] >= B[i]) {
                // Add the current element in B to ans and subtract it from A
                ans += B[i];
                A[i + 1] -= B[i];
                // Set the current element in B to 0
                B[i] = 0;
            } else {
                // Add the current element in A to ans and subtract it from B
                ans += A[i + 1];
                B[i] -= A[i + 1];
                // Set the current element in A to 0
                A[i + 1] = 0;
            }
        }
        
        // Print the final result
        System.out.println(ans);
    }
}
