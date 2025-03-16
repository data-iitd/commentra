
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arrA = new int[n];
		for (int i = 0; i < n; i++) {
			arrA[i] = sc.nextInt();
		}

		// Initialize variables
		int[] cumSumA = new int[n+1];
		cumSumA[0] = 0;
		for (int i = 0; i < n; i++) {
			cumSumA[i+1] = cumSumA[i] + arrA[i];
		}

		// Initialize variable to store the answer
		int ans = Integer.MAX_VALUE;

		// Iterate through the array to find the answer
		for (int i = 1; i < n; i++) {
			int temp = cumSumA[n] - 2*cumSumA[i];
			if (Math.abs(temp) < ans) {
				ans = temp;
			}
		}

		// Print the answer
		System.out.println(ans);

		// End of the code
	}

}

