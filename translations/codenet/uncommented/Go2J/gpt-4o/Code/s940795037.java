import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        
        int n = sc.nextInt();
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += 1.0 / sc.nextInt();
        }
        System.out.printf("%f\n", 1.0 / ans);
    }
}

class Scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Scanner() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
