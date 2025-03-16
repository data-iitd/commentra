import java.io.*; // Import the Java I/O package
import java.util.*; // Import the Java Utilities package

public class Main {

    private void solve() { // Define a private method named solve
        int x = nextInt(); // Read the first integer x
        int t = nextInt(); // Read the second integer t
        int a = nextInt(); // Read the third integer a
        int b = nextInt(); // Read the fourth integer b
        int da = nextInt(); // Read the fifth integer da
        int db = nextInt(); // Read the sixth integer db

        int first = 0; // Initialize first to zero
        int second = 0; // Initialize second to zero
        boolean ok = false; // Initialize ok to false

        // Run a nested loop to find first and second
        for (int i = 0; i < t; i++) {
            first = a - (da * i); // Calculate first for the current i
            for (int j = 0; j < t; j++) {
                second = b - (db * j); // Calculate second for the current j

                // Check if second + first equals x or if either first or second equals x
                if (second + first == x || second == x || first == x || x == 0) {
                    ok = true; // Set ok to true if a match is found
                    break; // Exit the inner loop if a match is found
                }
            }
        }

        // Print YES if ok is true, otherwise print NO
        if (ok) {
            out.print("YES");
        } else {
            out.print("NO");
        }
    }

    public static void main(String[] args) { // Define a public static main method
        new Main().run(); // Create an instance of Main and call its run method
    }

    BufferedReader br; // Declare a BufferedReader variable named br
    StringTokenizer st; // Declare a StringTokenizer variable named st
    PrintWriter out; // Declare a PrintWriter variable named out

    private void run() { // Define a private method named run
        try {
            br = new BufferedReader(new InputStreamReader(System.in)); // Initialize br
            out = new PrintWriter(System.out); // Initialize out
            solve(); // Call the solve method
            br.close(); // Close the input stream
            out.close(); // Close the output stream
        } catch (IOException e) {
            e.printStackTrace(); // Print the stack trace if an IOException occurs
        }
    }

    private int nextInt() { // Define a private method named nextInt
        return Integer.parseInt(next()); // Read an integer from the standard input
    }

    private String next() { // Define a private method named next
        while (st == null || !st.hasMoreTokens()) { // Read a token from the standard input
            try {
                st = new StringTokenizer(br.readLine()); // Initialize st with the next line from the input
            } catch (IOException e) {
                return "END_OF_FILE"; // Return END_OF_FILE if an IOException occurs
            }
        }
        return st.nextToken(); // Return the next token from st
    }
}
