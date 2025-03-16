import java.io.*;
import java.util.*;

public class Main {
    static final int MAGIC = 1000000007;
    static int N;
    static int[] p = new int[200000];

    // find function checks if a given number n is present in the p array
    static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }

    // solve function contains the main logic of the problem
    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        // Parse input
        int X = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        // Check if X or its neighbors are present in the p array
        for (int i = 0; i <= 100; i++) {
            if (find(X - i) == 1) {
                out.println(X - i);
                out.flush();
                return;
            }
            if (find(X + i) == 1) {
                out.println(X + i);
                out.flush();
                return;
            }
        }

        // If no valid number is found, you can print a default message or handle it as needed
        out.println("No valid number found");
        out.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(); // Call the solve function
    }
}

// <END-OF-CODE>
