import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements N from input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize an array A to hold N integers
        int[] A = new int[N];

        // Read N integers from input into the array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Sort the array A in ascending order
        Arrays.sort(A);

        // Initialize a variable to hold the total difference sum
        int ans = 0;

        // Calculate the sum of differences between consecutive elements in the sorted array
        for (int i = 1; i < N; i++) {
            ans += A[i] - A[i - 1];
        }

        // Output the total sum of differences
        System.out.println(ans);
    }
}

// <END-OF-CODE>
