
import java.util.Scanner;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) {
		// Declare variables
		int n;
		String str, com;
		HashMap<String, Boolean> T = new HashMap<String, Boolean>(); // A map to store strings as keys and boolean values

		// Read the number of input pairs from the standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		// Iterate through each input pair
		for (int i = 0; i < n; i++) {
			// Read the command and the string from the standard input
			com = sc.next();
			str = sc.next();

			// If the command is 'i', add the string to the map with a value of true
			if (com.equals("i")) {
				T.put(str, true); // Set the value of the string as a key in the map to true
			}
			// If the command is not 'i', check if the string is present in the map and print the result accordingly
			else {
				if (T.containsKey(str)) { // Check if the string is present in the map
					System.out.println("yes"); // If present, print 'yes'
				}
				else {
					System.out.println("no"); // If not present, print 'no'
				}
			}
		}
		// Return 0 to indicate successful execution of the program
		return 0;
	}
}

