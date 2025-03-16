import java.util.*; // Include the Java utilities library.
import java.io.*; // Include the Java I/O library.

public class Main{ // Define the Main class.
	public static void main(String[] args) throws IOException{ // Define the main method of the Main class.
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read from the standard input.
		int n = sc.nextInt(); // Read the value of n from the standard input.
		long[] a = new long[n + 1]; // Create an array to store the input values.
		long[] pre = new long[n + 1]; // Create an array to store the prefix sums.
		long[] last = new long[n + 1]; // Create an array to store the suffix sums.
		for(int i = 1;i <= n;i++){ // Loop to read n integers into the array a.
			a[i] = sc.nextLong(); // Read the i-th integer and store it in a[i].
		}
		long sumpre = 0,sumlast = 0; // Declare variables to store the cumulative sums of prefix and suffix.
		for(int i = 1;i < n;i++){ // Loop to calculate the prefix sums.
			sumpre = sumpre + a[i]; // Add the current element to the cumulative sum.
			pre[i] = sumpre; // Store the cumulative sum in the pre array.
		}
		for(int i = n;i > 1;i--){ // Loop to calculate the suffix sums.
			sumlast = sumlast + a[i]; // Add the current element to the cumulative sum.
			last[i] = sumlast; // Store the cumulative sum in the last array.
		}
		long d = (1ll << 60); // Declare a variable to store the minimum difference and initialize it to a large number.
		for(int i = 1;i < n;i++){ // Loop to find the minimum absolute difference between prefix and suffix sums.
			d = Math.min(d,Math.abs(pre[i] - last[i + 1])); // Update the minimum difference if a smaller one is found.
		}
		System.out.println(d); // Print the minimum difference found.
	}
}

