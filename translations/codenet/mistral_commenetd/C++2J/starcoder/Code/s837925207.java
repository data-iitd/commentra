
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x, ans = 0; // Initialize x and ans to zero

		// Read input value of x from the user
		x = sc.nextInt();

		// Calculate the answer using the given formula
		ans = x + x*x + x*x*x;

		// Output the answer to the user
		System.out.println(ans);
	}
}

