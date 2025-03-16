import java.util.Scanner; // Importing the Scanner class for user input

class Main {

	public static void main(String[] args) { // Main method to start the program
		Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read user input
		
		// Read three integers from the user
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		scan.close(); // Closing the Scanner to save system resources

		// Check if 'a' is less than 'b' and 'b' is less than 'c' and 'a' is less than 'c'
		if(a < b && b < c && a < c) {
			System.out.println("Yes"); // Print "Yes" if the condition is true
			
		}else { // Else, if the condition is false
			System.out.println("No"); // Print "No"
		}
	}

}
