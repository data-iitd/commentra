
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new scanner for reading from standard input
		Scanner s = new Scanner(System.in);

		// Read the first two lines from standard input and store them in the scanner
		s.nextLine();
		s.nextLine();

		// Assign the text of the second line to the variable ds
		String ds = s.nextLine();

		// Split the string ds into an array of strings dd using the strings.Split function
		String[] dd = ds.split(" ");

		// Create a new slice dn of length len(dd) and initialize each element to 0 using make function
		int[] dn = new int[dd.length];

		// Iterate through each element i in the slice dd and convert its string value to integer using Integer.parseInt function and store it in the corresponding index of slice dn
		for (int i = 0; i < dd.length; i++) {
			dn[i] = Integer.parseInt(dd[i]);
		}

		// Initialize sum variable to 0
		int sum = 0;

		// Iterate through each index i in the slice dn
		for (int i = 0; i < dn.length; i++) {
			// Iterate through each index j greater than i in the slice dn
			for (int j = i + 1; j < dn.length; j++) {
				// Add the product of dn[i] and dn[j] to the sum variable
				sum += dn[i] * dn[j];
			}
		}

		// Print the value of sum variable to the standard output using System.out.println function
		System.out.println(sum);

		// End of code
	}
}

