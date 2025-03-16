
// Take the input string 's' and an integer 'n' from the user
Scanner sc = new Scanner ( System.in );
String s = sc.nextLine ();
int n = sc.nextInt ();

// Initialize the answer variable 'ans' to 0
int ans = 0;

// Iterate through the given range 'n' times
for ( int i = 0; i < n; i++ ) {

    // Take the next string 'x' as input
    String x = sc.nextLine ();

    // Initialize variables 'a' and 'b' to 0
    int a = 0, b = 0;

    // Iterate through each character 'j' in the string 's'
    for ( int j = 0; j < s.length (); j++ ) {

        // If the character 'j' matches the first character of the string 'x', increment 'a'
        if ( s.charAt ( j ) == x.charAt ( 0 ) ) {
            a++;
        }

        // If the character 'j' matches the second character of the string 'x', increment 'b'
        else if ( s.charAt ( j ) == x.charAt ( 1 ) ) {
            b++;
        }

        // If the current character 'j' does not match any character in the string 'x',
        // add the minimum of 'a' and 'b' to the answer variable 'ans' and reset 'a' and 'b' to 0
        else {
            ans += Math.min ( a, b );
            a = 0;
            b = 0;
        }
    }

    // Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
    ans += Math.min ( a, b );
}

// Print the final answer
System.out.println ( ans );

