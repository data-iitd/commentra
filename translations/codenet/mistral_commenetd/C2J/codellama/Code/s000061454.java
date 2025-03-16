
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Declare variables
		int a, b, n, sum;
		int i, j;

		// Initialize variables
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			// Read input values a, b, and n from the user
			a = sc.nextInt();
			b = sc.nextInt();
			n = sc.nextInt();

			// Calculate a = a - a/b * b
			a-=a/b*b;

			// Initialize sum to zero
			sum=0;

			// Perform the main calculation for n times
			for(i=1;i<=n;i++) {
				// Multiply a by 10
				a*=10;

				// Find the largest multiple of b less than or equal to a
				for(j=9;j>=0;j--) {
					// Check if b*j is less than or equal to a
					if(b*j<=a) {
						// Subtract the multiple of b from a
						a-=b*j;

						// Add the digit j to the sum
						sum+=j;

						// Break the inner loop since we have found the largest multiple
						break;
					}
				}
			}

			// Print the result
			System.out.println(sum);
		}
	}
}

