import java.util.*; // We import the Java Util library to use Scanner class

public class Main { // Main class declaration
	public static void main(String args[]) { // Main method declaration
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the console

		// Read the number of strings to be processed
		int N = Integer.parseInt(sc.next());

		// Create an array of strings with size N
		String s[] = new String[N];

		// Initialize counters for 'A' and 'B' strings
		int a_num = 0;
		int b_num = 0;

		// Initialize a flag to check if there is a string with both 'A' and 'B' at the beginning or end
		boolean flag = true;

		// Initialize an answer variable
		int ans = 0;

		// Process each string in the array
		for(int i = 0; i < N; i++) {
			// Read the next string from the console
			s[i] = sc.next();

			// Count the number of 'B' strings
			if(s[i].substring(0, 1).equals("B")) {
				b_num++;
			}

			// Count the number of 'A' strings
			if(s[i].substring(s[i].length() - 1, s[i].length()).equals("A")){
				a_num++;
			}

			// Check if the current string has both 'A' and 'B' at the beginning or end
			if(s[i].substring(0, 1).equals("B") || s[i].substring(s[i].length() - 1, s[i].length()).equals("A")) {
				// If the current string has only one of 'A' or 'B' at the beginning or end, set the flag to false
				if(!(s[i].substring(0, 1).equals("B") && s[i].substring(s[i].length() - 1, s[i].length()).equals("A"))) {
					flag = false;
				}
			}

			// Count the number of 'AB' pairs in the current string
			for(int j = 0; j < s[i].length() - 1; j++) {
				if(s[i].substring(j, j + 2).equals("AB")) {
					ans++; // Increment the answer variable
				}
			}
		}

		// Add the minimum number of 'A' and 'B' strings to the answer
		ans += Math.min(a_num, b_num);

		// If there is a string with both 'A' and 'B' at the beginning or end and the flag is true, decrement the answer
		if(Math.min(a_num, b_num) != 0 && flag) {
			ans--;
		}

		// Print the answer
		System.out.println(ans);
	}
}
