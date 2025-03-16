
// by syu
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Initialize a new scanner for reading input
Scanner in = new Scanner(System.in);

public class Main {
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

class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner(InputStreamReader isr) {
        br = new BufferedReader(isr);
    }

    public int nextInt() {
        try {
            String line = br.readLine();
            if (line == null) {
                return -1;
            }
            st = new StringTokenizer(line);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return Integer.parseInt(st.nextToken());
    }
}

// Print a line with the given arguments
public static void Pln(Object... s) {
    System.out.println(s);
}

