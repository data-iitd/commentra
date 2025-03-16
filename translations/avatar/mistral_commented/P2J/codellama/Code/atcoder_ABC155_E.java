# Import necessary libraries
import java.util.Scanner;

// Define main function 'main_b'
public static void main_b ( ) {
    // Read input string 's'
    Scanner sc = new Scanner ( System.in );
    String s = sc.nextLine ( );

    // Initialize variables 'pp' and 'na'
    int pp = 0;
    int na = 0;

    // Iterate through each character in the input string 's'
    for ( int i = 0 ; i < s.length ( ) ; i++ ) {
        // Calculate current character value 'cc'
        int cc = na + s.charAt ( i ) - '0';
        na = 0;

        // Update 'pp' based on the current character value 'cc'
        if ( cc <= 4 ) {
            pp += cc;
        } else {
            // If current character is the last character, add 1 to 'pp'
            if ( i == s.length ( ) - 1 ) {
                pp += 1;
            } else {
                // Otherwise, add 10 - 'cc' to 'pp'
                pp += 10 - cc;
            }
        }
    }

    // Print the result 'pp'
    System.out.println ( pp );
}

// Define main function 'main'
public static int main ( ) {
    // Read input string 's'
    Scanner sc = new Scanner ( System.in );
    String s = sc.nextLine ( );

    // Initialize variables 'pmin' and 'mmin' with large initial values
    int pmin = 1000;
    int mmin = 0;

    // Add a leading zero to the input string 's'
    s = "0" + s;

    // Iterate through each character in the input string 's'
    for ( int i = 0 ; i < s.length ( ) ; i++ ) {
        // Calculate new minimum values 'npmin' and 'nmmin' based on current character value 'v' and previous minimum values 'pmin' and 'mmin'
        int npmin = Math.min ( pmin + 10 - ( s.charAt ( i ) - '0' + 1 ) , mmin + 10 - ( s.charAt ( i ) - '0' ) );
        int nmmin = Math.min ( pmin + ( s.charAt ( i ) - '0' + 1 ) , mmin + ( s.charAt ( i ) - '0' ) );

        // Update 'pmin' and 'mmin' with the new minimum values
        pmin = npmin;
        mmin = nmmin;
    }

    // Return the minimum value between 'pmin' and 'mmin'
    return Math.min ( pmin , mmin );
}

// Define a helper function 'pa' to print values during testing
public static void pa ( int v ) {
    if ( isTest ) {
        System.out.println ( v );
    }
}

// Define function to read input from clipboard
public static String input_clipboard ( ) {
    String input_text = "";
    try {
        java.awt.datatransfer.Clipboard clipboard = Toolkit.getDefaultToolkit ( ).getSystemClipboard ( );
        java.awt.datatransfer.Transferable clipboard_content = clipboard.getContents ( null );
        if ( clipboard_content != null && clipboard_content.isDataFlavorSupported ( DataFlavor.stringFlavor ) ) {
            input_text = ( String ) clipboard_content.getTransferData ( DataFlavor.stringFlavor );
        }
    } catch ( Exception e ) {
        e.printStackTrace ( );
    }
    return input_text;
}

// Main program execution starts here
public static void main ( String [ ] args ) {
    // Check current platform and set input method accordingly
    if ( System.getProperty ( "os.name" ).equals ( "iOS" ) ) {
        if ( input_method == input_methods [ 0 ] ) {
            String input_text = input_clipboard ( );
            String [ ] input_l = input_text.split ( "\n" );
            for ( String l : input_l ) {
                System.out.println ( l );
            }
            isTest = true;
        } else if ( input_method == input_methods [ 1 ] ) {
            System.setIn ( new FileInputStream ( "inputFile.txt" ) );
        } else {
            pass
        }
    } else {
        pass
    }

    // Call main function and print result
    int ret = main ( );
    if ( ret != -1 ) {
        System.out.println ( ret );
    }
}

