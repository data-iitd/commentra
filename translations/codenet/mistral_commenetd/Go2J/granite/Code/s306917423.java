
import java.util.Scanner; // Importing the 'Scanner' class for input/output operations

public class s306917423{
	public static void main(String[] args) {
		// Creating a 'Scanner' object to read input from the user
		Scanner scanner = new Scanner(System.in);

		// Declaring a variable's' of type 'String' to store the input string
		String s = scanner.nextLine();

		// Declaring a variable 'ans' of type 'int' to store the answer
		int ans = 0;

		// Looping through each character 'c' in the string's'
		for (char c : s.toCharArray()) {
			// Checking if the current character 'c' is equal to '1'
			if (c == '1') {
				// Incrementing the answer if the character is '1'
				ans++;
			}
		}

		// Printing the answer using 'System.out.println' function
		System.out.println(ans);

		// End of the code
		scanner.close();
	}
}

