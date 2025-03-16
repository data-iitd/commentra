import java.util.*;
import java.io.*;

public class Main {
    static final long MOD = 1000000007;
    static final double INF = Double.POSITIVE_INFINITY;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        long q = Long.parseLong(st.nextToken());
        long h = Long.parseLong(st.nextToken());
        long s = Long.parseLong(st.nextToken());
        long d = Long.parseLong(st.nextToken());
        int n = Integer.parseInt(br.readLine());

        long best1L = Math.min(q * 4, Math.min(h * 2, s));
        long best2L = Math.min(d, best1L * 2);

        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2));
        } else {
            System.out.println(best2L * (n / 2) + best1L);
        }
    }
}
// <END-OF-CODE>
