
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements in the sequence
		int n = new Scanner(System.in).nextInt();

		// Initialize the answer and the previous element in the sequence
		int ans = 0;
		int aPrev = 0;
		// Loop through each element in the sequence
		for (int i = 0; i < n; i++) {
			// Read the current element
			int a = new Scanner(System.in).nextInt();
			// Check the conditions for the current element
			switch (true) {
			case a > i || a > aPrev + 1:
				// If the condition is met, print -1 and exit
				System.out.println(-1);
				return;
			case a == aPrev + 1:
				// If the current element is one more than the previous, increment the answer
				ans++;
			default:
				// Otherwise, add the current element's value to the answer
				ans += a;
			}
			// Update the previous element to the current element
			aPrev = a;
		}
		// Print the final answer after processing all elements
		System.out.println(ans);
	}
}

