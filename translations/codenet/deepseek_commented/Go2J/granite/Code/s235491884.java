
import java.util.Scanner; // Importing the Scanner class for reading user input

public class s235491884{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the user
		String s = scanner.nextLine(); // Reading input from the user and storing it in the variable s

		int n = countOccurrences(s, "o"); // Counting the number of occurrences of "o" in the string s and storing the result in n
		System.out.println(700 + n*100); // Printing the final score based on the count of "o" characters
	}

	public static int countOccurrences(String str, String searchStr) {
		int count = 0; // Initializing a counter variable to keep track of the number of occurrences
		int idx = 0; // Initializing an index variable to keep track of the current position in the string

		while ((idx = str.indexOf(searchStr, idx))!= -1) { // Looping until the search string is not found in the string
			count++; // Incrementing the count of occurrences
			idx += searchStr.length(); // Advancing the index to search for the next occurrence
		}

		return count; // Returning the total count of occurrences
	}
}

