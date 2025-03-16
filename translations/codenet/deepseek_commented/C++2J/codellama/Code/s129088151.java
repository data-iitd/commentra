import java.util.Scanner; // Import the Scanner class for input/output operations
import java.util.HashMap; // Import the HashMap class for efficient key-value pair storage
import java.util.Map; // Import the Map interface for efficient key-value pair storage

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
		int n = sc.nextInt(); // Read the number of operations from the user
		Map<String, Boolean> T = new HashMap<>(); // Create a HashMap to store the presence of strings
		for (int i = 0; i < n; i++) { // Loop through each operation
			String com = sc.next(); // Read the command
			String str = sc.next(); // Read the string
			if (com.equals("i")) T.put(str, true); // If the command is 'i', insert the string into the map
			else { // If the command is not 'i'
				if (T.containsKey(str)) System.out.println("yes"); // Check if the string is present in the map and print 'yes'
				else System.out.println("no"); // If the string is not present, print 'no'
			}
		}
	}
}
