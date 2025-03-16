// by syu
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        // Initialize a new Scanner for reading input from standard input (System.in)
        Scanner in = new Scanner(System.in, 0);

        // Read two integers n and k from the input
        int n = in.nextInt();
        int k = in.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0
            System.out.println(0);
        } else {
            // If n is not divisible by k, print 1
            System.out.println(1);
        }
    }
}

class Scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Scanner(InputStream input, int max) {
        reader = new BufferedReader(new InputStreamReader(input));
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String nextLine = reader.readLine();
            if (nextLine == null) {
                return null;
            }
            tokenizer = new StringTokenizer(nextLine);
        }
        return tokenizer.nextToken();
    }
}

