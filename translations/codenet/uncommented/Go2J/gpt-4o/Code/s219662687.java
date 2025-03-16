import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int INF = (int) Math.pow(10, 11);
        
        int A = nextInt(sc);
        int B = nextInt(sc);
        int Q = nextInt(sc);
        
        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        for (int i = 1; i <= A; i++) {
            s[i] = nextInt(sc);
        }
        
        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        for (int i = 1; i <= B; i++) {
            t[i] = nextInt(sc);
        }
        
        for (int i = 0; i < Q; i++) {
            int x = nextInt(sc);
            int b = Arrays.binarySearch(s, x);
            if (b < 0) b = -b - 1; // If not found, get the insertion point
            int d = Arrays.binarySearch(t, x);
            if (d < 0) d = -d - 1; // If not found, get the insertion point
            
            int res = INF;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    int d1 = abs(S - x) + abs(T - S);
                    int d2 = abs(T - x) + abs(S - T);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }
            System.out.println(res);
        }
        
        sc.close();
    }

    private static int nextInt(Scanner sc) {
        return sc.nextInt();
    }

    private static int abs(int x) {
        return Math.abs(x);
    }
}
