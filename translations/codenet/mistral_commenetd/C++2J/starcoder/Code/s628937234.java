
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read from standard input

		String s = sc.next(); // Read a string from standard input and store it in the variable s

		// The following block of code creates a new string t from the string s
		String t = s.substring(0, 1);
		t += Integer.toString(s.length() - 2);
		t += s.substring(s.length() - 1, s.length());

		// Extract the first character from string s and store it in variable t
		// Convert the size of string s minus 2 to a string using to_string function
		// Concatenate the extracted first character, the size minus 2 as a string, and the last character of string s to create the new string t

		System.out.println(t); // Output the newly created string t to the standard output
	}
}

