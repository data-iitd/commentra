// Read the integer input which represents the length of the strings
int n = Integer.parseInt(scanner.nextLine());

// Read the first string and convert it to a list of characters
String s = scanner.nextLine();

// Read the second string and convert it to a list of characters
String t = scanner.nextLine();

// Check if both strings are identical
if (s.equals(t)) {
    // If they are the same, print the length of the strings
    System.out.println(n);
} else {
    // Initialize a counter to keep track of the matching characters
    int cnt = 0;
    
    // Iterate over each character in the first string
    for (int i = 0; i < n; i++) {
        // For each character, check the subsequent characters in the second string
        for (int j = 0; j < n - i; j++) {
            // If characters at the current position do not match, break the inner loop
            if (s.charAt(i + j) != t.charAt(j)) {
                break;
            }
            
            // If we have matched all characters from this starting point
            if (j == n - i - 1) {
                // Update the count of matching characters
                cnt = n - i;
            }
        }
    }
    
    // Print the result based on the number of matching characters found
    System.out.println(2 * n - cnt);
}

