import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements N
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Create a slice A to store N integers
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            // Read each integer and store it in slice A
            A[i] = sc.nextInt();
        }

        // Sort the slice A in ascending order
        Arrays.sort(A);

        // Initialize the answer variable to store the result
        int ans = 0;
        for (int i = 1; i < N; i++) {
            // Calculate the sum of differences between consecutive elements
            ans += A[i] - A[i-1];
        }

        // Print the result
        System.out.println(ans);
    }
}

