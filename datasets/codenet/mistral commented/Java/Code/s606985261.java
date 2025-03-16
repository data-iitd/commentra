
import java.util.Scanner; // Importing Scanner class for user input

public class Main {
	
	public static void main(String[] args) { // Main method to start the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input
		String s = sc.next(); // Reading a string input from the user
        
		int total = 0; // Initializing a variable 'total' to store the count of repeated characters
        
		for (int i = 0; i < s.length(); i++) { // Iterating through each character in the string 's'
			for ( int j = i + 1; j < s.length(); j++) { // Iterating through the remaining characters in the string starting from the next character of 'i'
				if (s.charAt(i) == s.charAt(j)) { // Checking if the characters at index 'i' and 'j' are same
					total++; // Incrementing the 'total' variable if the characters are same
				}
			}
		}
		
		System.out.println(total == 2 ? "Yes" : "No"); // Printing the output based on the condition whether 'total' is equal to 2 or not
	}
}

