
// Take an input string `ip` from the user
Scanner sc = new Scanner ( System.in );
String ip = sc.nextLine ();

// Initialize an empty string `st`
String st = "";

// Check if the length of the input string is not equal to 1
if ( ip.length ()!= 1 ) {

    // Check if the first character of the input string is equal to "9"
    if ( ip.charAt ( 0 ) == '9' ) {
        // Assign "9" to the variable `st`
        st = "9";
        // Slice the input string to exclude the first character
        ip = ip.substring ( 1 );
    }

    // Iterate through each character in the input string `ip`
    for ( int i = 0; i < ip.length (); i++ ) {

        // If the character is an integer greater than 4
        if ( Character.getNumericValue ( ip.charAt ( i ) ) > 4 ) {
            // Calculate the difference between 9 and the integer
            int n = 9 - Character.getNumericValue ( ip.charAt ( i ) );
            // Add the difference to the string `st`
            st += String.valueOf ( n );
        }

        // If the character is an integer less than or equal to 4
        else {
            // Add the character directly to the string `st`
            st += ip.charAt ( i );
        }
    }
}

// If the length of the input string is equal to 1
else {
    // Assign the input string to the variable `st`
    st = ip;
}

// Print the integer value of the string `st` to the console
System.out.println ( Integer.parseInt ( st ) );
