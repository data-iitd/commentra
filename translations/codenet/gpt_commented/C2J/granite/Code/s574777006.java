
import java.util.Scanner;

public class s574777006{
	
	public static void main(String[] args) {
		
		// Declare variables
		int n, i, j, q, x[] = new int[10000], y[] = new int[500], sum = 0;
		
		// Create a Scanner object to read input
		Scanner sc = new Scanner(System.in);
		
		// Read the number of elements in array x
		n = sc.nextInt();
		
		// Read n elements into array x
		for( i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}
		
		// Read the number of queries
		q = sc.nextInt();
		
		// Read q elements into array y
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
		
		// Close the Scanner object
		sc.close();
	}
}
