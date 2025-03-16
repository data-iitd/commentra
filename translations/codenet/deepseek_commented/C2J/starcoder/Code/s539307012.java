import java.util.Scanner;  // Import the standard input-output library

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);  // Create a Scanner object
		int n = sc.nextInt();  // Read an integer from standard input
		int x = sc.nextInt();  // Read an integer from standard input
		int min = sc.nextInt();  // Read an integer from standard input
		x -= min;  // Subtract the minimum value from x
		for (int i = 1; i < n; i++) {  // Start a loop from 1 to n-1
			int m = sc.nextInt();  // Read the next integer
			x -= m;  // Subtract the current integer from x
			if (min > m) {  // Check if the current integer is less than the current min
				min = m;  // Update min to the current integer if true
			}
		}
		System.out.println(n + x / min);  // Print the result
	}
}
