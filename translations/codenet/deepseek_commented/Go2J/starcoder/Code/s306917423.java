import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Read input from the standard input and store it in the variable `s`
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		
		// Initialize a variable to count the number of '1's in the input string
		int ans = 0;
		// Iterate over each character in the string `s`
		for (int i = 0; i < s.length(); i++) {
			// Check if the character is '1'
			if (s.charAt(i) == '1') {
				// Increment the count of '1's
				ans++;
			}
		}
		// Print the count of '1's to the standard output
		System.out.println(ans);
	}
}

