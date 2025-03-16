
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize variables N and R to zero
		int N = 0;
		int R = 0;

		// Read two integers from the standard input using Scanner class
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		R = sc.nextInt();

		// Check if N is greater than or equal to 10
		if(N >= 10) {
			// If condition is true, print the value of R
			System.out.println(R);
		} else {
			// If condition is false, print the value of R plus 100 times the difference between 10 and N
			System.out.println(R + 100*(10-N));
		}
	}
}

