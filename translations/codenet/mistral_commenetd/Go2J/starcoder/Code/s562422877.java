
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Initialize variables and read input
		// Code for A - Initialize variables and read input
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		int[] A = new int[N];
		System.out.println("Enter the elements of the array:");
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}

		// Sort the array in ascending order
		// Code for C - Sort the array
		Arrays.sort(A);

		// Calculate the answer
		// Code for D - Calculate the answer
		int ans = 0;
		System.out.println("Calculating the answer...");
		for (int i = 1; i < N; i++) {
			ans += A[i] - A[i-1];
		}

		// Print the answer
		// Code for E - Print the answer
		System.out.println("The answer is: " + ans);
	}
}

