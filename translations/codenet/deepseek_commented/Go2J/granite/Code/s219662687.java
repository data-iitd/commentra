
import java.util.*;

class s219662687 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int Q = sc.nextInt();
        int[] s = new int[A + 2];
        int[] t = new int[B + 2];
        s[0] = -1000000000;
        s[A + 1] = 1000000000;
        t[0] = -1000000000;
        t[B + 1] = 1000000000;
        for (int i = 1; i <= A; i++) {
            s[i] = sc.nextInt();
        }
        for (int i = 1; i <= B; i++) {
            t[i] = sc.nextInt();
        }
        for (int i = 0; i < Q; i++) {
            int x = sc.nextInt();
            int b = Arrays.binarySearch(s, x);
            int d = Arrays.binarySearch(t, x);
            int res = 1000000000;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    int d1 = Math.abs(S - x) + Math.abs(T - S);
                    int d2 = Math.abs(T - x) + Math.abs(S - T);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }
            System.out.println(res);
        }
    }
}

