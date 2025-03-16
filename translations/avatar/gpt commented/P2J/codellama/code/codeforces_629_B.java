
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] m = new int[N];
        int[] f = new int[N];
        int M = in.nextInt();
        for (int i = 0; i < M; i++) {
            String x = in.next();
            int a = in.nextInt();
            int b = in.nextInt();
            if (x.equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } else {
                f[a] += 2;
                f[b] -= 2;
            }
        }
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < N; i++) {
            a += m[i];
            b += f[i];
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);
            }
        }
        System.out.println(c);
    }
}

