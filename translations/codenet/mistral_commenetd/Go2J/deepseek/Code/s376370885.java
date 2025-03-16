import java.io.*;
import java.util.*;

public class Main {
    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is, int maxBuffer) throws IOException {
            br = new BufferedReader(new InputStreamReader(is));
            if (maxBuffer > 0) {
                br.mark(maxBuffer);
            }
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in, 1048576);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        if (n % k == 0) {
            System.out.println(0);
        } else {
            System.out.println(1);
        }
    }
}
