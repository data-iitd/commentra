
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize Scanner to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read a single word from the input
		String s = sc.next();
		
		// Calculate the length of the input string
		int n = s.length();
		
		// Initialize the answer variable to store the final result
		long ans = 0;
		
		// Generate all possible combinations of inserting '+' between the digits
		for(int mask = 0 ; mask < 1<<(n - 1) ; mask++) {
			// Initialize sum for the current combination
			long sum = 0;
			
			// Build the expression string based on the current combination
			String x = "" + s.charAt(0);
			for(int i = 0 ; i < n - 1 ; i++) {
				if((mask&(1<<i)) >= 1) {
					x += "+" + s.charAt(i + 1);
				} else {
					x += s.charAt(i + 1);
				}
			}
			
			// Split the expression string by '+' and sum up the values
			String[] split = x.split("\\+");
			for(int i = 0 ; i < split.length ; i++) {
				sum += Long.valueOf(split[i]);
			}
			
			// Add the sum of the current combination to the final answer
			ans += sum;
		}
		
		// Print the final result
		System.out.println(ans);
	}
}