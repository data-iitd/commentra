import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        long[] s = new long[n];
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            s[i] = Long.parseLong(st.nextToken());
        }

        boolean[] u = new boolean[n];
        long m = 0;
        long f;

        for (int c = 1; c < n - 1; c++) {
            f = 0;
            for (int k = 0; c < n - 1 - k * c; k++) {
                u[k * c] = true;
                if (u[n - 1 - k * c]) break;
                f += s[n - 1 - k * c] + s[k * c];
                if (m < f) m = f;
            }
            for (int k = 0; k * c < n - 1; k++) {
                u[k * c] = false;
            }
        }
        System.out.println(m);
    }
}
