
// Step 1: Import the Scanner class.
import java.util.Scanner;

public class Main {
	
	// Step 2: Declare the necessary variables.
	static int a, b, c, i, count;
	
	public static void main(String[] args) {
		
		// Step 3: Create a Scanner object.
		Scanner sc = new Scanner(System.in);
		
		// Step 4: Read the input values for a, b, and c.
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		// Step 5: Initialize the count variable to zero.
		count = 0;
		
		// Step 6: Start a for loop from a to b.
		for (i = a; i <= b; i++) {
			// Step 7: Check if c is divisible by i.
			if (c % i == 0)
				// Step 8: Increment the count if the condition is true.
				count++;
		}
		
		// Step 9: Print the count.
		System.out.println(count);
		
		// Step 10: Close the Scanner object.
		sc.close();
	}
}

