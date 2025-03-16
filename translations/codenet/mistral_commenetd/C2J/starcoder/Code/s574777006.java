
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements in the array x
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Allocate memory for array x
		int[] x = new int[n];

		// Read each element of array x
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}

		// Read the number of queries
		int q = sc.nextInt();

		// Allocate memory for array y
		int[] y = new int[q];

		// Read each element of array y
		for(int i = 0; i < q; i++) {
			y[i] = sc.nextInt();
		}

		// Initialize sum to zero
		int sum = 0;

		// Check if each element of array y is present in array x and increment sum if found
		for(int i = 0; i < q; i++) {
			for(int j = 0; j < n; j++) {
				// Check if current element of y is equal to current element of x
				if( y[i]==x[j]) {
					// Increment sum if found
					sum = sum + 1;
					// Break out of inner loop as soon as a match is found
					break ;
				}
			}
		}

		// Print the value of sum
		System.out.println(sum);

		// Return 0 to indicate successful execution
		return 0;
	}
}

