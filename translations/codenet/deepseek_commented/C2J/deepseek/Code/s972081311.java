import java.util.Scanner;

public class SumOfNaturalNumbers {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n, sum;
		
		// Step 4: Read input from the user
		n = scanner.nextInt();
		
		// Step 5: Calculate the sum of the first n natural numbers
		sum = (n * (n + 1)) / 2;
		
		// Step 6: Print the result
		System.out.println(sum);
		
		// Step 7: Close the scanner
		scanner.close();
	}
}
