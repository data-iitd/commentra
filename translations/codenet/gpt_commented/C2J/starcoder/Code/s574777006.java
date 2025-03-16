
import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		// Declare variables
		int n, i, j, q, x[], y[], sum = 0;
		
		// Read the number of elements in array x
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		// Read n elements into array x
		x = new int[n];
		for( i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}
		
		// Read the number of queries
		q = sc.nextInt();
		
		// Read q elements into array y
		y = new int[q];
		for( i = 0; i < q; i++) {
			y[i] = sc.nextInt();
		}
		
		// Initialize sum to count how many elements in y are found in x
		for( i = 0; i < q; i++) {
			// Check each element in y against all elements in x
			for( j = 0; j < n; j++) {
				// If a match is found, increment sum and break the inner loop
				if( y[i] == x[j]) {
					sum = sum + 1;
					break;
				}
			}
		}
		
		// Output the total count of matches found
		System.out.println(sum);
		
		sc.close();
	}
}

