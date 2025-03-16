import java.util.*; // Importing the Scanner class for input operations

public class Main {
	public static void main(String[] args) { // Main method, entry point of the program
		Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input from the user
		
		// Read two integers from the user
		int firstNumber = sc.nextInt();
		int secondNumber = sc.nextInt();
		
		// Compare the remainder of the first number when divided by 500 with the second number
		// Print "Yes" if the remainder is less than or equal to the second number, otherwise print "No"
		System.out.println(firstNumber % 500 <= secondNumber ? "Yes" : "No");
	}
}
