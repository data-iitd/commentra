import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the number of elements N from input
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		// Initialize a slice A to hold N integers
		int[] A = new int[N];
		
		// Read N integers from input into the slice A
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}

		// Sort the slice A in ascending order
		Arrays.sort(A);

		// Initialize a variable to hold the total difference sum
		int ans = 0;
		
		// Calculate the sum of differences between consecutive elements in the sorted slice
		for (int i = 1; i < N; i++) {
			ans += A[i] - A[i-1];
		}

		// Output the total sum of differences
		System.out.println(ans);
	}
}

