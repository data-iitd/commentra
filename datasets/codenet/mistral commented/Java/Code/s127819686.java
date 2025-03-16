import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
	public static void main(String[] args){ // Starting point of the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input
		
		// Input section
		int a = sc.nextInt(); // Reading the first integer input from the user
		int b = sc.nextInt(); // Reading the second integer input from the user
		
		// Calculation section
		int hb = b / 2; // Calculate the value of hb by dividing b by 2
		
		// Output section
		System.out.println(a + hb); // Print the sum of the input integer 'a' and the calculated value of 'hb'
	}
}
