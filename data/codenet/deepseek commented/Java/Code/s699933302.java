
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		// Initialize Scanner to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read three integers from the user: a, b, and c
		int a = Integer.parseInt(sc.next()); 
		int b = Integer.parseInt(sc.next()); 
		int c = Integer.parseInt(sc.next()); 
		
		// Initialize a counter to keep track of divisors
		int count = 0;
		
		// Loop through the range from a to b
		for (int i = a ; i <= b ;i++  ) {
			// Check if c is divisible by the current number i
			if (c % i == 0) {
				// Increment the counter if i is a divisor of c
				count++;
			}
		}
		
		// Print the number of divisors found
		System.out.println(count);
	}
}

