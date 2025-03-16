
import java.io.BufferedReader ; // Importing BufferedReader for reading input
import java.io.IOException ; // Importing IOException for handling exceptions
import java.io.InputStreamReader ; // Importing InputStreamReader for reading input stream

public class Main {
    public static void main ( String [ ] subhani ) throws IOException {
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Creating a BufferedReader object to read input from the user
        int n = Integer.parseInt ( br.readLine ( ) ) ; // Reading an integer input from the user and storing it in variable n
        solve ( n ) ; // Calling the solve method with the input value n
    }

    public static void solve ( int n ) {
        // Calculating the result based on the given logic
        System.out.println ( ( n / 3 ) * 2 + ( n % 3 == 0 ? 0 : 1 ) ) ; // Printing the result to the console
    }
}
