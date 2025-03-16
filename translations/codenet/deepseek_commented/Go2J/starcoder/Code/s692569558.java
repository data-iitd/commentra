
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Create a new scanner to read from standard input
		Scanner s = new Scanner(System.in);
		
		// Read the first line of input (which we will ignore)
		s.nextLine();
		
		// Read the second line of input
		String ds = s.nextLine();
		
		// Split the input string into a slice of strings
		String[] dd = ds.split(" ");
		
		// Create a slice of integers to hold the converted values
		int[] dn = new int[dd.length];
		
		// Convert each string in the slice to an integer
		for (int i = 0; i < dd.length; i++) {
			dn[i] = Integer.parseInt(dd[i]);
		}
		
		// Initialize the sum variable to hold the result
		int sum = 0;
		
		// Calculate the sum of the products of all pairs of integers in the slice
		for (int i = 0; i < dn.length; i++) {
			for (int j = i + 1; j < dn.length; j++) {
				sum += dn[i] * dn[j];
			}
		}
		
		// Print the result
		System.out.println(sum);
	}
}

