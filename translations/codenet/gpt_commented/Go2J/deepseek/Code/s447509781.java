import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        long[] s = new long[n];
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            s[i] = Long.parseLong(tokenizer.nextToken());
        }
        
        boolean[] u = new boolean[n];
        long m = 0, f = 0;
        
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
