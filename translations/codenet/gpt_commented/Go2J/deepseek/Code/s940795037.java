import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int n = sc.nextInt();
        double ans = 0.0;

        for (int i = 0; i < n; i++) {
            double tmp = 1.0 / sc.nextInt();
            ans += tmp;
        }

        System.out.printf("%.10f\n", 1.0 / ans);
    }

    static class Scanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
