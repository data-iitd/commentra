import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable to hold the size of the arrays
		int n;
		// Read the size of the arrays from standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		// Initialize two slices: one for array 'as' with size n+1 and another for array 'bs' with size n
		int[] as = new int[n+1];
		int[] bs = new int[n];

		// Read values into the 'as' array
		for (int i = 0; i < as.length; i++) {
			as[i] = sc.nextInt();
		}

		// Read values into the 'bs' array
		for (int i = 0; i < bs.length; i++) {
			bs[i] = sc.nextInt();
		}

		// Initialize a variable to hold the cumulative sum
		int sum = 0;
		// Iterate through the elements of the arrays
		for (int i = 0; i <= n-1; i++) {
			int a = as[i]; // Current element from 'as'
			int b = bs[i]; // Current element from 'bs'
			
			// Check if the current element of 'as' is less than or equal to the current element of 'bs'
			if (a <= b) {
				sum += a; // Add 'a' to the sum
				b -= a;   // Subtract 'a' from 'b'
				
				// Check if there is a next element in 'as'
				if (i+1 <= n) {
					int an = as[i+1]; // Next element from 'as'
					// Check if the next element of 'as' can be fully accommodated by the remaining 'b'
					if (an <= b) {
						sum += an; // Add the next element to the sum
						as[i+1] = 0; // Set the next element to zero since it has been fully used
					} else {
						sum += b; // Add the remaining 'b' to the sum
						as[i+1] -= b; // Subtract the used portion from the next element of 'as'
					}
				}
			} else {
				// If 'a' is greater than 'b', add 'b' to the sum
				sum += b;
			}
		}
		// Output the final computed sum
		System.out.println(sum);
	}
}

