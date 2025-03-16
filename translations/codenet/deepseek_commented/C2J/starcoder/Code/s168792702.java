import java.util.Scanner;  // Import the Scanner class

public class Main {  // Define the main class
	public static void main(String[] args) {  // Define the main function, the entry point of the program
		Scanner input = new Scanner(System.in);  // Create a Scanner object to read from standard input
		
		int a = input.nextInt();  // Read an integer from the user and store it in variable a
		int b = input.nextInt();  // Read an integer from the user and store it in variable b
		int c = input.nextInt();  // Read an integer from the user and store it in variable c
		
		if (a < b && b < c) System.out.println("Yes");  // Check if a is less than b and b is less than c, and print "Yes" if true
		else System.out.println("No");  // Print "No" if the condition is not met
	}
}
