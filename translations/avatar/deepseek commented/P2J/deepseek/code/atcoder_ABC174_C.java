import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static int ceil(int a, int b) {
        return (a + b - 1) / b;
    }
    static int sqrt(int x) {
        return (int) Math.sqrt(x);
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(br.readLine().trim());
        int t = 0;
        for (int i = 1; i <= k; i++) {
            t = (t % k) * 10 + 7;
            if (t % k == 0) {
                pw.println(i);
                pw.flush();
                return;
            }
        }
        pw.println(-1);
        pw.flush();
    }
}
