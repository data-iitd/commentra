// Define a list containing all the vowels in upper and lower case
char[] vo = { 'a' , 'e' , 'i' , 'o' , 'u' , 'y' , 'A' , 'E' , 'I' , 'O' , 'U' , 'Y' };

// Take an input string 'a' from the user
Scanner sc = new Scanner ( System.in );
String a = sc.nextLine ( );

// Iterate through the string 'a' from the end to the beginning
for ( int i = a.length ( ) - 1 ; i >= 0 ; i-- ) {
    // If the current character is a space or a question mark, skip it and move on to the next character
    if ( a.charAt ( i ) == ' ' || a.charAt ( i ) == '?' ) {
        continue;
    }
    // If the current character is not a space or a question mark, check if it is a vowel or not
    else {
        // Check if the current character is a vowel
        if ( a.charAt ( i ) == 'a' || a.charAt ( i ) == 'e' || a.charAt ( i ) == 'i' || a.charAt ( i ) == 'o' || a.charAt ( i ) == 'u' || a.charAt ( i ) == 'y' || a.charAt ( i ) == 'A' || a.charAt ( i ) == 'E' || a.charAt ( i ) == 'I' || a.charAt ( i ) == 'O' || a.charAt ( i ) == 'U' || a.charAt ( i ) == 'Y' ) {
            // If it is, print "YES" and break out of the loop
            System.out.println ( "YES" );
            break;
        }
        // If it is not, print "NO" and break out of the loop
        else {
            System.out.println ( "NO" );
            break;
        }
    }
}

// End of code
