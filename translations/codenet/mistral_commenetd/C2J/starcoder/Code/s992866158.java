import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a Scanner object for reading the input
		Scanner sc = new Scanner(System.in);
		// Read two integers n and k from the standard input using the Scanner object
		int n = sc.nextInt();
		int k = sc.nextInt();
		// Initialize variable cnt to zero
		int cnt = 0;
		// Loop through n times using a while loop
		while (n-- > 0) {
			// Read an integer h from the standard input using the Scanner object
			int h = sc.nextInt();
			// If h is greater than or equal to k, increment cnt by 1
			if (h >= k)
				cnt++;
		}
		// Print the value of cnt to the standard output using the System.out object
		System.out.println(cnt);
	}
}
