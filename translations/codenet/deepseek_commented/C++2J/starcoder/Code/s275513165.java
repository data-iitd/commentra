import java.util.*; // Include the necessary header files for input and output operations

public class Main { // The main class is the entry point of the program
	public static void main(String[] args) { // The main method is the entry point of the program
		Scanner input = new Scanner(System.in); // Create a Scanner object to read input from the standard input
		String str = input.next(); // Read a string from the standard input and store it in the string variable str
		if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) System.out.println("Yes"); // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
		else System.out.println("No"); // If the conditions are not met, output "No"
	}
}
