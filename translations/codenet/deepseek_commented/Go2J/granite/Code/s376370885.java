

// by syu
import java.io.*;
import java.util.*;

public class s376370885{
    public static void main(String[] args) throws IOException {
        // Initialize a global Scanner instance to read from standard input
        Scanner in = new Scanner(System.in);

        // Read two integers, n and k, from standard input
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

// Define a custom Scanner class to read input efficiently
class Scanner {
    BufferedReader br;
    StringTokenizer st;

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

