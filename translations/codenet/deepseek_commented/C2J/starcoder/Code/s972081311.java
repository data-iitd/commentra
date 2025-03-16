
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Step 1: Declare and initialize variables
		int n, sum;
		
		// Step 2: Read input from the user
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		// Step 3: Calculate the sum of the first n natural numbers
		sum = (n * (n + 1)) / 2;
		
		// Step 4: Print the result
		System.out.println(sum);
	}
}

