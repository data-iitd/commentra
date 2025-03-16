
import java.util.Scanner; // Import the necessary classes for input and output operations

public class s275513165{ // Declare the main class of the program
  	public static void main(String[] args) { // The main function is the entry point of the program
    	Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
    	String str = sc.nextLine(); // Read a string from the user and store it in the string variable str
    	if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) System.out.println("Yes"); // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
    	else System.out.println("No"); // If the conditions are not met, output "No"
  	}
}
