// Take an integer 'n' as input
int n = Integer.parseInt(input());

// Take two lists's' and 't' of length 'n' as input
String s = input();
String t = input();

// Check if both lists's' and 't' are equal or not
if (s.equals(t)) {
    // If they are equal, print the value of 'n'
    System.out.println(n);
} else {
    // Initialize a counter 'cnt' to store the length of the longest common substring
    int cnt = 0;

    // Iterate through all possible substrings of's' starting from the first character
    for (int i = 0; i < n; i++) {
        // Iterate through all possible substrings of 't' starting from the first character
        for (int j = 0; j < n - i; j++) {
            // Check if the substring of's' starting from index 'i+j' is equal to the substring of 't' starting from index 'j'
            if (s.charAt(i + j)!= t.charAt(j)) {
                // If they are not equal, break the inner loop and move to the next substring of's'
                break;
            }

            // If they are equal and we have reached the end of the substring of's', update the value of 'cnt'
            if (j == n - i - 1) {
                cnt = n - i;
            }
        }
    }

    // If's' and 't' have no common substring, 'cnt' will be 0. In that case, print 2*n
    System.out.println(2 * n - cnt);
}

