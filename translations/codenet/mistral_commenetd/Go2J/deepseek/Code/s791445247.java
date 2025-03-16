import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public int Int() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner();
        int n = in.Int();
        int k = in.Int();

        if (n % k == 0) {
            System.out.println(0);
        } else {
            System.out.println(1);
        }
    }
}
