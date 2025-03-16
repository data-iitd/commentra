
import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main { // Declare the Main class
	public static void main(String[] args) { // Declare the main function with no arguments and no return value
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from the standard input
		String str = sc.nextLine(); // Read a string from the standard input and store it in str
		String p = sc.nextLine(); // Read another string from the standard input and store it in p
		String tmp = str; // Copy the contents of str to tmp
		str += tmp; // Concatenate the contents of str and tmp, i.e., str now contains str concatenated with itself
		int slen = str.length(); // Get the length of str and store it in slen
		int plen = p.length(); // Get the length of p and store it in plen
		int flag = 0; // Initialize flag to 0
		for (int i = 0; i < slen - plen; i++) { // Iterate through the string str from the beginning to the end - plen characters
			if (str.substring(i, i + plen).equals(p)) { // Compare the substring of str starting from index i with length plen to p
				flag = 1; // If the comparison is successful, set flag to 1
			}
		}
		if (flag == 1) System.out.println("Yes"); // If flag is 1, print "Yes" to the standard output
		else System.out.println("No"); // If flag is 0, print "No" to the standard output
	}
}

