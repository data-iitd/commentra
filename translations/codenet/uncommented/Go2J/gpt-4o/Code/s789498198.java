import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        if ((A + B) % 2 == 0) {
            System.out.println((A + B) / 2);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

        public int[] nextInts() throws IOException {
            String line = br.readLine();
            String[] tokens = line.split(" ");
            int[] result = new int[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                result[i] = Integer.parseInt(tokens[i]);
            }
            return result;
        }
    }
}
