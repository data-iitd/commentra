import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        
        // Reads three integers H, W, and N from the standard input.
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        
        // Determines the maximum of H and W and assigns it to A.
        int A = Math.max(H, W);
        
        // Calculates the result by dividing N by A and rounding up.
        // This is done by adding N-1 to the division result and then performing integer division by A.
        System.out.println((N + A - 1) / A);
    }
}

// Custom Scanner class to read input efficiently.
class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    // Reads the next integer from the input buffer.
    public int nextInt() throws IOException {
        if (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
}
