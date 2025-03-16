import java.util.Scanner;

public class Main {
    private static int res = 0;

    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        // Recursive function to explore combinations of numbers
        rec(new int[0], N, M, Q, a, b, c, d);
        
        // Print the maximum score found
        System.out.println(res);
    }

    private static void rec(int[] A, int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        // Base case: if the length of A equals N, calculate the score
        if (A.length == N) {
            int ans = 0;
            // Check each query to see if it contributes to the score
            for (int i = 0; i < Q; i++) {
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];  // Add the score from the query if it matches
                }
            }
            // Update the maximum score found
            res = Math.max(res, ans);
            return;
        }

        // Determine the starting point for the next number to be added
        int lastMax = (A.length == 0) ? 1 : A[A.length - 1];

        // Iterate through possible values to add to the combination
        for (int i = lastMax; i <= M; i++) {
            int[] newA = new int[A.length + 1];
            System.arraycopy(A, 0, newA, 0, A.length);
            newA[A.length] = i;  // Add the new number to A
            rec(newA, N, M, Q, a, b, c, d);  // Recursively call with the new number added to A
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N, M, and Q from input
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Q = scanner.nextInt();
        
        // Initialize arrays to hold the query parameters
        int[] a = new int[Q];
        int[] b = new int[Q];
        int[] c = new int[Q];
        int[] d = new int[Q];
        
        // Read the query parameters from input
        for (int i = 0; i < Q; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
            d[i] = scanner.nextInt();
        }
        
        // Call the solve function with the parsed input
        solve(N, M, Q, a, b, c, d);
        
        scanner.close();
    }
}

// <END-OF-CODE>
