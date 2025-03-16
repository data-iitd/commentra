import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input values from the standard input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();

        // Allocate memory for an integer array A of size N
        int[] A = new int[N];

        // Allocate memory for a vector B of size N
        Vector<Integer> B = new Vector<Integer>(N);

        // Read integer values from the standard input and store them in array A
        for(int i = 0; i < N; i++) A[i] = sc.nextInt();

        // Initialize variable m with the minimum value among the first two elements of array A
        int m = A[0];
        if(A[1] < m) m = A[1];

        // Set the first element of vector B with the difference between the second element of array A and the initialized value of m
        B.set(1, A[1] - m);

        // Iterate through the remaining elements of array A starting from the third one
        for(int i = 2; i < N; i++){
            // Update the value of m with the minimum value between it and the current element of array A
            m = Math.min(m, A[i]);

            // Set the current element of vector B with the difference between the current element of array A and the updated value of m
            B.set(i, A[i] - m);
        }

        // Print the output value to the standard output
        System.out.println(Collections.frequency(B, Collections.max(B)));

        // End of main function
    }
}
