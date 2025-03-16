// by syu
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Define a custom scanner type that wraps BufferedReader
class Scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Scanner(BufferedReader reader) {
        this.reader = reader;
    }

    public String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}

// Define a custom scanner instance for reading input from standard input
Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

// Define a custom printer instance for printing output to standard output
class Printer {
    private static final String LINE_SEPARATOR = System.getProperty("line.separator");

    public void println(Object... args) {
        System.out.println(LINE_SEPARATOR + String.format("%s", args));
    }
}

// Define a custom printer instance for printing output to standard output
Printer out = new Printer();

// Entry point of the program
public static void main(String[] args) throws IOException {
    // Read two integers n and k from standard input
    int n = in.nextInt();
    int k = in.nextInt();
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        out.println(0);
    } else {
        // If n is not divisible by k, print 1 to the console
        out.println(1);
    }
}

