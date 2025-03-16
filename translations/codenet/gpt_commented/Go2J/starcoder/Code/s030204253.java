import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements from standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Initialize a slice to hold the float64 numbers
		double[] a = new double[n];

		// Read n float64 numbers from standard input into the slice
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextDouble();
		}

		// Perform a series of operations to reduce the slice
		for (int i = 0; i + 1 < n; i++) {
			// Sort the slice in ascending order
			Arrays.sort(a);

			// Create a new slice to hold the modified values
			double[] na = new double[0];

			// Append all elements from the third element onward to the new slice
			for (int j = 2; j < a.length; j++) {
				na = Arrays.copyOf(na, na.length + 1);
				na[na.length - 1] = a[j];
			}

			// Calculate the average of the first two elements and append it to the new slice
			na = Arrays.copyOf(na, na.length + 1);
			na[na.length - 1] = (a[0] + a[1]) / 2;

			// Update the original slice to be the new slice
			a = na;
		}

		// Print the final remaining element in the slice
		System.out.println(a[0]);
	}
}

