import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Run(System.in, System.out);
    }

    public static void Run(InputStreamReader r, PrintWriter w) throws IOException {
        Scanner sc = new Scanner(r);
        
        int N = sc.nextInt();
        int D = sc.nextInt();
        
        int count = 0;
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            double d = Math.sqrt(x * x + y * y);
            if (D >= d) {
                count++;
            }
        }
        w.println(count);
    }

    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStreamReader r) {
            br = new BufferedReader(r);
        }

        public String next() throws IOException {
            if (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}

// <END-OF-CODE>
