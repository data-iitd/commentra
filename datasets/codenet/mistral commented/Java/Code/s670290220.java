
import java.util.*;

class Main {
	public static void main(String[] args) {
		// Create a new Scanner object to read input
		Scanner sc = new Scanner(System.in);

		// Read the first integer `N` from the standard input
		int N = sc.nextInt();

		// Read the next token (which is a string) and convert it to a character array
		char c[] = sc.next().toCharArray();

		// Iterate through each character in the `c` array
		for (int i=0; i<c.length; i++) {
			// Calculate the new character value
			c[i] = (char)((c[i]-'A'+N) % 26 + 'A');
		}

		// Print the modified character array to the standard output
		System.out.println(c);
	}
}