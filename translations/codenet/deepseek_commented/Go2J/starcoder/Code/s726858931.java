
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read the input string.
		String s = sc.next();

		// Initialize the character to check against the string.
		char c = 'a';

		// Iterate through the alphabet to find the first missing character.
		for (int j = 0; j < 26; j++) {
			boolean found = false;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == c) {
					found = true;
					break;
				}
			}
			if (found == false) {
				System.out.println(c);
				return;
			}
			c++;
		}

		// If no missing character is found, print "None".
		System.out.println("None");
	}
}

