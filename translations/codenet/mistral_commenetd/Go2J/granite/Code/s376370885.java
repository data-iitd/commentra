
// by syu
import java.io.*;
import java.util.*;

class s376370885 {
    public static void main(String[] args) throws IOException {
        // Read two integers n and k from standard input
        int n = in.nextInt(), k = in.nextInt();
        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0 to the console
            out.println(0);
        } else {
            // If n is not divisible by k, print 1 to the console
            out.println(1);
        }
    }
}

// Define a custom scanner class that wraps BufferedReader
class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    // Initialize a new Scanner instance with the given reader
    public Scanner(Reader in) {
        br = new BufferedReader(in);
    }

    // Parse an integer from the current scanner data
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // Parse a string from the current scanner data
    public String next() throws IOException {
        while (st == null ||!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}

// Define a custom output stream class that wraps PrintWriter
class OutputWriter {
    private final PrintWriter writer;

    // Initialize a new OutputWriter instance with the given writer
    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    // Close the output stream
    public void close() {
        writer.close();
    }

    // Print a line to the console with the given arguments
    public void println(Object... objects) {
        print(objects);
        writer.println();
    }

    // Print a line to the console with the given arguments
    public void print(Object... objects) {
        int n = objects.length;
        for (int i = 0; i < n; i++) {
            if (i!= 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }
}

// Define a custom input stream class that wraps Scanner
class InputReader {
    private Scanner scanner;

    // Initialize a new InputReader instance with the given reader
    public InputReader(Reader reader) {
        scanner = new Scanner(reader);
    }

    // Parse an integer from the current input stream
    public int nextInt() throws IOException {
        return scanner.nextInt();
    }

    // Parse a string from the current input stream
    public String next() throws IOException {
        return scanner.next();
    }

    // Close the input stream
    public void close() {
        scanner.close();
    }
}

// Define a global instance of InputReader
static InputReader in = new InputReader(new InputStreamReader(System.in));

// Define a global instance of OutputWriter
static OutputWriter out = new OutputWriter(new OutputStreamWriter(System.out));

// Entry point of the program
public static void main(String[] args) throws IOException {
    // Read two integers n and k from standard input
    int n = in.nextInt(), k = in.nextInt();
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        out.println(0);
    } else {
        // If n is not divisible by k, print 1 to the console
        out.println(1);
    }
    // Close the output stream
    out.close();
}

// End of code