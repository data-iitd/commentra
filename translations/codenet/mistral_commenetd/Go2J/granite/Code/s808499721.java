
// Define the main method as the entry point of our program
public class s808499721{
	// Define the main method as the entry point of our program
	public static void main(String[] args) {
		// Initialize a variable x of type int and read a value from the standard input using Scanner
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();

		// Initialize an answer variable ans with a default value of 0
		int ans = 0;

		// Check the value of x and assign an appropriate value to ans based on the range of x using if statements
		if (x >= 400 && x <= 599) {
			// If x is between 400 and 599, assign the value 8 to ans
			ans = 8;
		}
		if (x >= 600 && x <= 799) {
			// If x is between 600 and 799, assign the value 7 to ans
			ans = 7;
		}
		if (x >= 800 && x <= 999) {
			// If x is between 800 and 999, assign the value 6 to ans
			ans = 6;
		}
		if (x >= 1000 && x <= 1199) {
			// If x is between 1000 and 1199, assign the value 5 to ans
			ans = 5;
		}
		if (x >= 1200 && x <= 1399) {
			// If x is between 1200 and 1399, assign the value 4 to ans
			ans = 4;
		}
		if (x >= 1400 && x <= 1599) {
			// If x is between 1400 and 1599, assign the value 3 to ans
			ans = 3;
		}
		if (x >= 1600 && x <= 1799) {
			// If x is between 1600 and 1799, assign the value 2 to ans
			ans = 2;
		}
		if (x >= 1800 && x <= 9999) {
			// If x is between 1800 and 9999, assign the value 1 to ans
			ans = 1;
		}

		// Print the value of ans using System.out.println
		System.out.println(ans);
	}
}

// 

