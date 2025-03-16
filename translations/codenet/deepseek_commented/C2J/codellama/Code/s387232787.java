
// Array to store the count of each letter (a-z)
int[] c = new int[26];

public static void main(String[] args) {
	// Array to store the input string
	String str = "";
	
	// Read input strings until there are no more inputs
	while (true) {
		// Read input string
		str = scanner.nextLine();
		
		// Check if the input string is empty
		if (str.length() == 0) {
			break;
		}
		
		// Pointer to traverse the string
		char[] p = str.toCharArray();
		
		// Traverse each character in the string
		for (int i = 0; i < p.length; i++) {
			// Check if the character is a lowercase letter
			if (p[i] >= 'a' && p[i] <= 'z') {
				// Increment the count for the corresponding letter
				c[p[i] - 'a']++;
			} 
			// Check if the character is an uppercase letter
			else if (p[i] >= 'A' && p[i] <= 'Z') {
				// Increment the count for the corresponding letter
				c[p[i] - 'A']++;
			}
		}
	}
	
	// Print the counts for each letter from 'a' to 'z'
	for (int i = 0; i < 26; i++) {
		System.out.println((char)('a' + i) + " : " + c[i]); 
	}
}

