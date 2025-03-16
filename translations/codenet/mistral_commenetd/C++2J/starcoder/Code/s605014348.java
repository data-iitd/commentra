
import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Read the input number
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		// Print the input number
		System.out.print(num + ":");

		// Continue the process until the number becomes 1
		while(num!=1){
			// Print the greatest divisor of the current number
			System.out.print(" " + div(num));
			// Divide the current number by its greatest divisor
			num = num / div(num);
		}
		// Print a newline character to move the cursor to the next line
		System.out.println();
	}

	// Function to find the greatest divisor of a given number
	public static int div(int n){
		// If the number is even, return 2 as the greatest divisor
		if(n%2 == 0) return 2;
		// Calculate the square root of the number
		int s= (int) Math.sqrt(n);
		// Check for divisibility by odd numbers from 3 to the square root
		for(int i=3; i<=s; i+=2){
			// If the number is divisible by the current odd number, return it as the greatest divisor
			if(n%i == 0) return i;
		}

		// If no divisor is found, return the number itself
		return n;
	}
}

