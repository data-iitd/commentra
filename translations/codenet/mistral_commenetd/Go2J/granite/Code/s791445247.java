

// by syu
import java.io.*;
import java.util.*;

public class s791445247{
    // Initialize a new scanner for reading input
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        // Read the first two integers from the standard input
        int n = in.nextInt();
        int k = in.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If it is, print 0
            System.out.println(0);
        } else {
            // If not, print 1
            System.out.println(1);
        }
    }
}

// Define a new Scanner class
class Scanner {
    // Initialize a new BufferedReader instance
    BufferedReader br;
    // Initialize a new StringTokenizer instance
    StringTokenizer st;

    public Scanner(Reader in) {
        // Initialize the BufferedReader instance
        br = new BufferedReader(in);
    }

    public Scanner(InputStream in) {
        // Initialize the BufferedReader instance with the provided InputStream
        this(new InputStreamReader(in));
    }

    // Read the next token as a string
    public String next() {
        // If the StringTokenizer instance doesn't have more tokens, tokenize the next line
        if (st == null ||!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        // Return the next token
        return st.nextToken();
    }

    // Parse an integer from a string
    public int nextInt() {
        // Return the integer value of the next token
        return Integer.parseInt(next());
    }
}

// Print a line with the given arguments
public static void Pln(Object... o) {
    // Print the line with the given arguments
    System.out.println(Arrays.deepToString(o));
}

