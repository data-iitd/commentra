import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Create a new scanner to read input from standard input (System.in)
		Scanner sc = new Scanner(System.in);
		
		// Read the next line of input
		sc.nextLine();
		// Store the input text in variable's'
		String s = sc.nextLine();
		
		// Calculate the difference between lowercase and uppercase letters
		int d = 'a' - 'A';
		
		// Iterate over each rune (character) in the input string
		for (int i = 0; i < s.length(); i++) {
			// Initialize a variable to hold the modified character
			char rr = s.charAt(i);
			
			// Check if the character is an uppercase letter
			if ('A' <= rr && rr <= 'Z') {
				// Convert uppercase to lowercase by adding the difference
				rr = (char) (rr + d);
			} else if ('a' <= rr && rr <= 'z') {
				// Convert lowercase to uppercase by subtracting the difference
				rr = (char) (rr - d);
			}
			
			// Print the modified character
			System.out.print(rr);
		}
		
		// Print a newline at the end of the output
		System.out.println();
	}

}
