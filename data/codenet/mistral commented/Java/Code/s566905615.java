
import java.util.*; // Import the Scanner class

class Main{
	public static void main(String[] args){
		// Create a new Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		// Declare and initialize three integer variables to read user input
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		// Declare a string variable to store the answer
		String answer = "No";
		// Begin an if statement to check whether a + b >= c
		if(a + b >= c) {
			// If the condition is true, update the answer to "Yes"
			answer = "Yes";
		}
		// Print the answer to the standard output stream
		System.out.println(answer);
		// Close the Scanner object to free up system resources
		sc.close();
	}
}