
// Importing required packages
import java.util.Scanner;

// Declaring a class named 's278875041'
public class s278875041{

	// s278875041 method
	public static void main(String[] args) {

		// Declaring a variable 'a' of type String
		String a = "";

		// Creating a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);

		// Reading a string input from the user using sc.next()
		a = sc.next();

		// Declaring a temporary variable 'tmp' of type String
		String tmp = a.replaceAll("1", "0");

		// Replacing all occurrences of '1' with '0' in the string 'a'
		// and storing the result in the variable 'tmp'

		String b = tmp.replaceAll("9", "1");

		// Replacing all occurrences of '9' with '1' in the string 'tmp'
		// and storing the result in the variable 'b'

		String ans = b.replaceAll("0", "9");

		// Replacing all occurrences of '0' with '9' in the string 'b'
		// and storing the result in the variable 'ans'

		// Printing the final answer using System.out.println()
		System.out.println(ans);

		// Closing the Scanner object
		sc.close();
	}
}

// Printing the final answer