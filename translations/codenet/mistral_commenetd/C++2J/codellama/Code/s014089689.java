
import java.util.Scanner; // Import the Scanner class for input and output operations

public class Main { // Beginning of the Main class
	public static void main(String[] args) { // Beginning of the main function
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input
		int n = sc.nextInt(); // Read the size of the string from the standard input
		String s = sc.next(); // Read the string from the standard input
		int cnt = 0; // Initialize a counter variable 'cnt' to 0

		// Beginning of the first for loop
		for (int i = 0; i < n; i++) { // Loop through each character in the string 's'
			cnt++; // Increment the counter variable 'cnt'
			int j = i + 1; // Initialize a variable 'j' to check for the next character

			// Beginning of the inner for loop
			for (; j < n; j++) { // Compare the current character with the next characters in the string
				if (s.charAt(i) != s.charAt(j)) { // If the current character is not equal to the next character
					break; // Exit the inner for loop
				}
			}
			i = j - 1; // If the current character is repeated, update the index 'i' to the previous index
		}

		// Output the result
		System.out.println(cnt); // Print the value of the counter variable 'cnt' to the standard output
	}
}

