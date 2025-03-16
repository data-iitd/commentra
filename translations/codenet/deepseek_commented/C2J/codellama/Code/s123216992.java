// Step 1: Include the standard input/output library.
import java.util.Scanner;

// Step 2: Define a function named 'swap' that takes two integer references as arguments.
void swap(int a, int b) {
	int tmp;  // Step 3: Inside the 'swap' function, declare a temporary variable 'tmp'.
	tmp = a;  // Step 4: Assign the value of 'a' to 'tmp'.
	a = b;  // Step 5: Assign the value of 'b' to 'a'.
	b = tmp;  // Step 6: Assign the value of 'tmp' to 'b'.
}

public class Main {  // Step 7: In the 'Main' class, declare two integer variables 'a' and 'b'.
	public static void main(String[] args) {  // Step 8: In the 'main' function, create an infinite loop using 'while(true)'.
		Scanner sc = new Scanner(System.in);  // Step 9: Create a new 'Scanner' object to read input from the user.
		while(true) {
			int a = sc.nextInt();  // Step 10: Read an integer from the user and store it in 'a'.
			int b = sc.nextInt();  // Step 11: Read an integer from the user and store it in 'b'.
			if (a == 0 && b == 0) break;  // Step 12: Check if both 'a' and 'b' are zero. If true, break the loop.
			if (b < a) swap(a, b);  // Step 13: Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
			System.out.println(a + " " + b);  // Step 14: Print the values of 'a' and 'b'.
		}
	}
}

