
import java.util.*;
class codeforces_629_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = 368;
        int[] m = new int[N];
        int[] f = new int[N];
        int i, j, k, a, b, c;
        for (i = 0; i < sc.nextInt(); i++) {
            String x = sc.next();
            a = sc.nextInt();
            b = sc.nextInt() + 1;
            if (x.equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } else {
                f[a] += 2;
                f[b] -= 2;
            }
        }
        a = b = c = 0;
        for (i = 0; i < N; i++) {
            a += m[i];
            b += f[i];
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);
            }
        }
        System.out.println(c);
    }
}
