import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Set the scanner to split input by whitespace
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("\\s");
		
		// Read two integers from input: n (number of elements) and k (some parameter)
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		// Read 'n' integers into slice 'a'
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		
		// Avoid unused variable error by assigning a value to the first element of 'a'
		a[0] = 0;
		
		// Initialize sum with the value of k and set ans to 1
		int sum = k;
		int ans = 1;
		
		// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
		while (sum < n) {
			sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
			ans++; // Increment the answer counter
		}
		
		// Print the final answer
		System.out.println(ans);
	}

}
