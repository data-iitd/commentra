
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Importing Scanner to read input from the user
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		
		// Reading an integer input from the user
		int n = scan.nextInt();
		
		// Initializing a variable to accumulate the sum of numbers
		int count = 0;
		
		// A for loop to iterate from 1 to n (inclusive) and add each number to count
		for (int i = 1; i <= n; i++) {
			count += i;
		}
		
		// Printing the final value of count to the console
		System.out.println(count);

	}

}

