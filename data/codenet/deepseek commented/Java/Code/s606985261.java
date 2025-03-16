import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		// Read a string input from the user
		String s = sc.next();
		// Initialize a variable to count the number of character pairs that are the same
		int total = 0;
		
		// Nested for loop to iterate over all pairs of characters in the string
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				// Check if the characters at positions i and j are the same
				if (s.charAt(i) == s.charAt(j)) {
					// Increment the total variable if a match is found
					total++;
				}
			}
		}
		
		// Check if the total number of matching character pairs is equal to 2
		// Print "Yes" if true, otherwise print "No"
		System.out.println(total == 2 ? "Yes" : "No");
	}
}