import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Array to store the count of each letter (a-z)
		int[] c = new int[26];
		
		// Read input strings until there are no more inputs
		while (sc.hasNext()) {
			// Array to store the input string
			char[] str = sc.next().toCharArray();
			
			// Pointer to traverse the string
			int p = 0;
			
			// Traverse each character in the string
			for (; p < str.length; p++) {
				// Check if the character is a lowercase letter
				if ('a' <= str[p] && str[p] <= 'z') {
					// Increment the count for the corresponding letter
					c[str[p] - 'a']++;
				} 
				// Check if the character is an uppercase letter
				else if ('A' <= str[p] && str[p] <= 'Z') {
					// Increment the count for the corresponding letter
					c[str[p] - 'A']++;
				}
			}
		}
		
		// Print the counts for each letter from 'a' to 'z'
		for (int i = 0; i < 26; i++) {
			System.out.println((char)('a' + i) + " : " + c[i]); 
		}
	}
}

