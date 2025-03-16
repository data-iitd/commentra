import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char[] s = scanner.next().toCharArray(), t = scanner.next().toCharArray(); // Reading input strings
		boolean check = false; // Initializing the check flag

		// Loop to find a position in s where t can be placed
		for (int i = s.length - t.length; i >= 0; i--) {
			boolean check2 = true; // Flag to check if t matches the substring of s

			// Inner loop to check if t matches the substring of s starting at position i
			for (int j = 0; j < t.length; j++) {
				if (s[i + j] != '?' && s[i + j] != t[j]) {
					check2 = false; // If characters do not match, set check2 to false
				}
			}

			// If a match is found, update s with t
			if (check2) {
				check = true; // Set check to true as a match is found
				for (int j = 0; j < t.length; j++) {
					s[i + j] = t[j]; // Replace the matched part with t
				}
			}

			// If a match is found, break out of the loop
			if (check) {
				break;
			}
		}

		// If a match is found, print the modified s, replacing '?' with 'a'
		if (check) {
			for (int i = 0; i < s.length; i++) {
				if (s[i] == '?') {
					System.out.print("a");
				} else {
					System.out.print(s[i]);
				}
			}
			System.out.println();
		} else {
			// If no match is found, print "UNRESTORABLE"
			System.out.println("UNRESTORABLE");
		}
	}
}
