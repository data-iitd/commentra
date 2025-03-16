import java.util.*;
import static java.lang.System.*;
import java.math.*;

public class Main {

	// Main method where the program execution starts
	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Define an array of strings representing the days of the week
		String[] youbi = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
		
		// Read a string input from the user
		String s = sc.next();
		
		// Initialize a variable to store the result
		int ans = 0;
		
		// Iterate through the days of the week array to find the index of the input string
		for(int i = 0; i < youbi.length; i++) {
			if (youbi[i].equals(s)) {
				// Calculate the number of days until the next weekend based on the index found
				ans = 7 - i;
			}
		}
		
		// Print the result
		out.println(ans);
		
	}
}
