
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        int[] dl = new int[n];
        for (int i = 0; i < n; i++) {
            if (a[i] > i) {
                System.out.println(-1);
                return;
            }
            dl[i] = i - a[i];
        }
        int ans = 0;
        List<Ban> bans = new ArrayList<Ban>();
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

class Sp {
    public static final int LIM = 20; 
    public static final int N = 2e5 + 7;

    public static int[] mn = new int[LIM][N];
    public static int[] pw = new int[N];

    // Initialize the sparse table with the given array
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

    // Query the sparse table for the minimum value in the range [l, r)
    public static int get(int l, int r) {
        r++;
        int p = pw[r - l];
        return Math.min(mn[p][l], mn[p][r - (1 << p)]);
    }
}

class Ban {
    int l;
    int r;
    int val;

    Ban() {}

    Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
}

