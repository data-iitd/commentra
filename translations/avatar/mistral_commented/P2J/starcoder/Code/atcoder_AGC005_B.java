
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }
        int c = 0;
        for (int k = n - 1; k >= 1; k--) {
            int l = 1, r = 1;
            if (k > 0 && a[k - 1] > a[k]) {
                l += b[k - 1];
                unite(k - 1, k);
            }
            if (k + 1 < n && a[k + 1] > a[k]) {
                r += b[k + 1];
                unite(k + 1, k);
            }
            c += l * r * a[k];
        }
        System.out.println(c);
    }

    static int[] par, rank, size;

    static void init(int n) {
        par = new int[n];
        rank = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    static int root(int x) {
        return x == par[x]? x : (par[x] = root(par[x]));
    }

    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    static void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
}

