
import java.util.*;
import static java.lang.System.*; // Importing static methods from System class
import java.math.*; // Importing BigDecimal and BigInteger classes from Math package

public class Main {

	public static void main(String[] args) {
		// Creating a Scanner object to read input from the console
		Scanner sc = new Scanner(System.in);

		// Defining an array 'youbi' to store the names of weekdays
		String[] youbi = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

		// Reading a string input from the user
		String s = sc.next();

		// Initializing an integer variable 'ans' to store the answer
		int ans = 0;

		// Using a for loop to iterate through the 'youbi' array
		for(int i = 0; i < youbi.length; i++) {
			// Checking if the input string 's' matches the current weekday name in the 'youbi' array
			if (youbi[i].equals(s)) {
				// Calculating the answer by finding the index of the matched weekday and subtracting it from the total number of days in a week (7)
				ans = 7 - i;
			}
		}

		// Printing the answer to the console
		out.println(ans);

		// Closing the Scanner object to free up system resources
		sc.close();
	}
}