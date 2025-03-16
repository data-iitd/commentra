// by syu
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    // Initialize a new BufferedReader to read from standard input
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        // Read two integers n and k from input
        int n = Integer.parseInt(in.readLine());
        int k = Integer.parseInt(in.readLine());

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

