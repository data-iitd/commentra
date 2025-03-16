import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables to hold the integer input and the string input
		int n;
		String s;
		
		// Read an integer from standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		// Read a string from standard input
		s = sc.next();
		
		// Count the occurrences of the substring "ABC" in the input string
		// and print the result
		System.out.println(s.length() - s.replace("ABC", "").length());
	}
}
