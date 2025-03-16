// by syu
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Read two integers, n and k, from the input.
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		
		// Check if n is divisible by k.
		if (n % k == 0) {
			// If n is divisible by k, print 0.
			System.out.println(0);
		} else {
			// If n is not divisible by k, print 1.
			System.out.println(1);
		}
	}
}

// 