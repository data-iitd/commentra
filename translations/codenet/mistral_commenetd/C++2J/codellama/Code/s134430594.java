
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] dl = new int[n];
        for (int i = 0; i < n; i++) {
            dl[i] = i - a[i];
        }
        int ans = 0;
        List<Ban> bans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            ans += a[r];
            i = r;
            bans.add(new Ban(r - a[r], r, r - a[r]));
        }
        Sp.init(dl);
        for (Ban t : bans) {
            if (Sp.get(t.l, t.r) > t.val) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }
}

class Ban {
    int l;
    int r;
    int val;

    Ban(int l, int r, int val) {
        this.l = l;
        this.r = r;
        this.val = val;
    }
}

class Sp {
    static int[] mn = new int[LIM][N];
    static int[] pw = new int[N];

    public static void init(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i];
        }
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = Math.max(mn[i][j], mn[i][j + (1 << i)]);
            }
        }
        pw[1] = 0;
        for (int i = 2; i < N; i++) {
            pw[i] = pw[i / 2] + 1;
        }
    }

    public static int get(int l, int r) {
        r++;
        int p = pw[r - l];
        return Math.min(mn[p][l], mn[p][r - (1 << p)]);
    }
}

