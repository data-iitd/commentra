import java.util.*; // Include the standard Java library for input/output operations
import java.lang.*; // Include the standard Java library for string manipulation

public class Main {
	public static void main(String[] args) {
		int n; // Declare an integer variable to store the number of operations
		String str, com; // Declare string variables to store commands and strings
		Map<String, Boolean> T = new HashMap<String, Boolean>(); // Declare a map to store the presence of strings

		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin
		n = sc.nextInt(); // Read the number of operations from the user
		for (int i = 0; i < n; i++) { // Loop through each operation
			com = sc.next(); // Read the command
			str = sc.next(); // Read the string
			if (com.charAt(0) == 'i') T.put(str, true); // If the command is 'i', insert the string into the map
			else { // If the command is not 'i'
				if (T.containsKey(str)) System.out.println("yes"); // Check if the string is present in the map and print 'yes'
				else System.out.println("no"); // If the string is not present, print 'no'
			}
		}
	}
}
