import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read a string input from the user
		String s = sc.next();
        
		// Initialize a counter to keep track of duplicate characters
		int total = 0;
        
		// Outer loop to iterate through each character in the string
		for (int i = 0; i < s.length(); i++) {
			// Inner loop to compare the current character with the subsequent characters
			for (int j = i + 1; j < s.length(); j++) {
				// If a duplicate character is found, increment the total count
				if (s.charAt(i) == s.charAt(j)) {
					total++;
				}
			}
		}
		
		// Check if exactly two duplicate characters were found and print the result
		System.out.println(total == 2 ? "Yes" : "No");
	}
}
