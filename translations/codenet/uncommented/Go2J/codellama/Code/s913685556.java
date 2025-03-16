
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }

    static class Scanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        public int nextInt() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return Integer.parseInt(st.nextToken());
        }
    }
}

