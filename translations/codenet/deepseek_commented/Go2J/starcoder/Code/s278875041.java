import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Declare a string variable to hold user input
		String a;
		
		// Read input from the user and store it in `a`
		Scanner sc = new Scanner(System.in);
		a = sc.next();
		
		// Replace all occurrences of "1" with "0" in the string `a`
		String tmp = a.replace("1", "0");
		
		// Store the result of the first replacement in a temporary variable `tmp`
		// Replace all occurrences of "9" with "1" in the string `tmp`
		String b = tmp.replace("9", "1");
		
		// Store the result of the second replacement in the variable `b`
		// Replace all occurrences of "0" with "9" in the string `b`
		String ans = b.replace("0", "9");
		
		// Print the final result to the console
		System.out.println(ans);
	}
}

