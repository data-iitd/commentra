
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Step 2: Declare the necessary variables.
		int a, b, c, i, count;
		
		// Step 3: Read the input values for a, b, and c.
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		// Step 4: Initialize the count variable to zero.
		count = 0;
		
		// Step 5: Start a for loop from a to b.
		for (i = a; i <= b; i++) {
			// Step 6: Check if c is divisible by i.
			if (c % i == 0)
				// Step 7: Increment the count if the condition is true.
				count++;
		}
		
		// Step 8: Print the count.
		System.out.println(count);
		
		// Step 9: Return 0 to indicate successful execution.
		return 0;
	}

}
