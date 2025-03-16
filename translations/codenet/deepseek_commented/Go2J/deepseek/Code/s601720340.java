import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static final int magic = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));
        String[] tokens = reader.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int[] p = new int[200000];
        tokens = reader.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(tokens[i]);
        }

        tokens = reader.readLine().split(" ");
        int X = Integer.parseInt(tokens[0]);

        for (int i = 0; i <= 100; i++) {
            if (find(X - i, p, N) == 1) {
                writer.println(X - i);
                writer.flush();
                return;
            }
            if (find(X + i, p, N) == 1) {
                writer.println(X + i);
                writer.flush();
                return;
            }
        }
        writer.close();
    }

    public static int find(int n, int[] p, int N) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }
}
