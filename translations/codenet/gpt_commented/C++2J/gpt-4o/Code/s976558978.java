import java.io.*;
import java.util.*;

public class Main {
    // File pointers for input and output
    static BufferedReader _fin = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter _fout = new PrintWriter(System.out);

    // Function to read an integer
    static int readi() throws IOException {
        return Integer.parseInt(_fin.readLine().trim());
    }

    public static void main(String[] args) throws IOException {
        // Run local test with specified input file
        // Uncomment the following line to read from a file instead of standard input
        // _fin = new BufferedReader(new FileReader("dataabc155A.txt"));

        // Read two integers from input
        int a = readi();
        int b = readi();

        // Output the smaller integer b times
        if (a < b) {
            for (int i = 0; i < b; i++) {
                _fout.print(a);
                if (i < b - 1) _fout.print(" "); // Print space between numbers
            }
        } else {
            for (int i = 0; i < a; i++) {
                _fout.print(b);
                if (i < a - 1) _fout.print(" "); // Print space between numbers
            }
        }
        _fout.println(); // New line after output
        _fout.flush(); // Ensure all output is written
    }
}
//<END-OF-CODE>
