
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Declare a character array 'c' of size 26 to store the count of each character.
		int c[] = new int[26];
		// Declare a character array'str' of size 1200 to store the input string.
		char str[] = new char[1200];
		// Declare a pointer 'p' to traverse the string'str'.
		char p;
		// Use a loop to read strings from the standard input using scanf() until the end of file is reached.
		while (true) {
			Scanner sc = new Scanner(System.in);
			if (sc.hasNext()) {
				// Use a loop to copy the string read from the standard input to the character array'str'.
				for (int i = 0; i < str.length; i++) {
					str[i] = sc.next().charAt(0);
				}
				// Use a loop to traverse the string'str' and increment the count of each character in the 'c' array.
				for (int i = 0; i < str.length; i++) {
					p = str[i];
					if ('a' <= p && p <= 'z') {
						c[p - 'a']++;
					} else if ('A' <= p && p <= 'Z') {
						c[p - 'A']++;
					}
				}
			} else {
				break;
			}
		}
		// Use a loop to print the count of each character and its corresponding character.
		for (int i = 0; i < 26; i++) {
			System.out.println((char) ('a' + i) + " : " + c[i]);
		}
	}
}

