// Importing required packages
import java.util.*;
import java.lang.*;
import java.io.*;

// Declaring a class 'Main'
class Main {
	public static void main(String[] args) {
		// Reading a string input from the user using Scanner class
		Scanner sc = new Scanner(System.in);
		String a = sc.next();

		// Declaring a temporary variable 'tmp' of type string
		String tmp = a.replace("1", "0");

		// Replacing all occurrences of '1' with '0' in the string 'a'
		// and storing the result in the variable 'tmp'

		String b = tmp.replace("9", "1");

		// Replacing all occurrences of '9' with '1' in the string 'tmp'
		// and storing the result in the variable 'b'

		String ans = b.replace("0", "9");

		// Replacing all occurrences of '0' with '9' in the string 'b'
		// and storing the result in the variable 'ans'

		// Printing the final answer
		System.out.println(ans);
	}
}

// Printing the final answer

