
// Array to hold the count of each letter (a-z)
int[] c = new int[26];

// Read strings from standard input until EOF
while (true) {
    // Declare a string to hold the input
    String str = new String();

    // Read a string from standard input
    try {
        str = new java.util.Scanner(System.in).nextLine();
    } catch (java.util.NoSuchElementException e) {
        break;
    }

    // Iterate through each character in the string
    for (int i = 0; i < str.length(); i++) {
        // Check if the character is a lowercase letter
        if ('a' <= str.charAt(i) && str.charAt(i) <= 'z') {
            // Increment the count for the corresponding letter
            c[str.charAt(i) - 'a']++;
        } 
        // Check if the character is an uppercase letter
        else if ('A' <= str.charAt(i) && str.charAt(i) <= 'Z') {
            // Increment the count for the corresponding letter (converted to lowercase)
            c[str.charAt(i) - 'A']++;
        }
    }
}

// Print the count of each letter from 'a' to 'z'
for (int i = 0; i < 26; i++) {
    System.out.println((char)('a' + i) + " : " + c[i]); 
}

// Indicate that the program ended successfully
System.out.println("