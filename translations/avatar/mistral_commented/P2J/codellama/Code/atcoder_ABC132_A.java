// Take a string as input from the user
Scanner sc = new Scanner ( System.in );
String S = sc.nextLine ();

// Import the Counter function from the collections module to count the frequency of each character in the string
import java.util.HashMap;
import java.util.Map;

// Create a set Sa from the list of characters in the string S
Set < Character > Sa = new HashSet < Character > ();
for ( int i = 0; i < S.length (); i++ ) {
    Sa.add ( S.charAt ( i ) );
}

// Check if the length of the set Sa is equal to 2
if ( Sa.size () != 2 ) {
    // If not, print "No" and exit the program
    System.out.println ( "No" );
    return;
}

// Iterate through each character i in the set Sa
for ( Character i : Sa ) {
    // For each character i, check if its frequency in the string S is equal to 2 using the Counter dictionary c
    int count = 0;
    for ( int j = 0; j < S.length (); j++ ) {
        if ( S.charAt ( j ) == i ) {
            count++;
        }
    }
    if ( count != 2 ) {
        // If the frequency of any character is not equal to 2, print "No" and exit the program
        System.out.println ( "No" );
        return;
    }
}

// If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
System.out.println ( "Yes" );

