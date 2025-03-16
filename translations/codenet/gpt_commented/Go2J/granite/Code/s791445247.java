
// by syu
import java.io.*;
import java.util.*;

public class s791445247{
    public static void main(String[] args) throws IOException {
        // Initialize a new Scanner to read from standard input
        Scanner in = new Scanner(System.in);

        // Read two integers n and k from input
        int n = in.nextInt();
        int k = in.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If divisible, print 0
            System.out.println(0);
        } else {
            // If not divisible, print 1
            System.out.println(1);
        }
    }
}

// Scanner class wraps BufferedReader for custom functionality
class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner(Reader in) {
        br = new BufferedReader(in);
    }

    public Scanner(InputStream in) {
        this(new InputStreamReader(in));
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public String next() throws IOException {
        while (st == null ||!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}

// Pln is a helper function to print a line with a newline
public static void Pln(Object... o) {
    System.out.println(Arrays.deepToString(o));
}

