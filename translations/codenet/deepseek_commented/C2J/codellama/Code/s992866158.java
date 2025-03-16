
import java.util.Scanner; // Import necessary classes

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object
		int n = sc.nextInt(); // Read the first integer
		int k = sc.nextInt(); // Read the second integer
		int cnt = 0; // Initialize the count variable
		while (n-- > 0) { // Use a while loop to read each height
			int h = sc.nextInt(); // Read each height
			if (h >= k) // Check if the height is suitable
				cnt++; // Increment the count if the height is greater than or equal to k
		}
		System.out.println(cnt); // Print the final count
	}
}

