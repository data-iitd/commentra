
import java.util.*; // Importing the Scanner class for input operations

class Main{
public static void main(String[] args){ // Main method is the entry point of the program
	Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the user
	int a = sc.nextInt(); // Reading the first integer input
	int b = sc.nextInt(); // Reading the second integer input
	int c = sc.nextInt(); // Reading the third integer input
	String answer = "No"; // Initializing the answer variable to "No"
	if(a + b >= c) { // Checking if the sum of a and b is greater than or equal to c
		answer = "Yes"; // Changing the answer to "Yes" if the condition is true
	}
	System.out.println(answer); // Printing the final answer to the console
}
}

