import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		// Declare two string variables, s and t
		String s, t;
		
		// Read a string from the standard input and store it in s
		s = in.next();
		
		// Assign the first character of s to t
		t = s.substring(0, 1);
		
		// Append the size of s minus 2 to t
		t += Integer.toString(s.length() - 2);
		
		// Append the last character of s to t
		t += s.substring(s.length() - 1, s.length());
		
		// Print the modified string t
		System.out.println(t);
	}
}

