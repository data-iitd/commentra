
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the number of successful and failed runs from the standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		// Calculate the total time in milliseconds for the successful and failed runs
		int x = m*1900 + (n-m)*100;
		
		// Print the result of the expression (total time * 2^m)
		System.out.println(x * (int) Math.pow(2, m));
	}
}

