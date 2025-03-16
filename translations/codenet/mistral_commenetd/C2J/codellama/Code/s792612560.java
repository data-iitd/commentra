
import java.util.Scanner;

public class Factorial {
	public static void main(String[] args) {
		// Initialize variables
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long m = n;
		
		// Decrement n by 1
		n--;
		
		// Loop through n-1 times to calculate the factorial
		for(; n > 1; n--) {
			// Multiply m with current value of n
			m *= n;
		}
		
		// Print the result
		System.out.println(m);
		
		// Close the scanner
		sc.close();
	}
}

