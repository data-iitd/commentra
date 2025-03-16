
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] par = new int[n];
        int[] rank = new int[n];
        int[] size = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            b[sc.nextInt() - 1] = i;
        }
        long c = 0;
        for (int k = 0; k < n; k++) {
            int l = 1;
            int r = 1;
            if (k > 0 && b[k - 1] > b[k]) {
                l += size[root(k - 1)];
                unite(k - 1, k);
            }
            if (k + 1 < n && b[k + 1] > b[k]) {
                r += size[root(k + 1)];
                unite(k + 1, k);
            }
            c += (long) l * r * b[k];
        }
        System.out.println(c);
    }

    static int root(int x) {
        return x == par[x] ? x : root(par[x]);
    }

    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    static void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
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
}

