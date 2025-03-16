import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] par = new int[n];
        int[] rank = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        Arrays.fill(rank, 1);
        Arrays.fill(size, 1);

        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }

        long c = 0;
        for (int k : b) {
            int l = 1, r = 1;
            if (k > 0 && a[k - 1] > a[k]) {
                l += size[find(par, k - 1)];
                unite(par, rank, size, k - 1, k);
            }
            if (k < n - 1 && a[k + 1] > a[k]) {
                r += size[find(par, k + 1)];
                unite(par, rank, size, k + 1, k);
            }
            c += l * r * a[k];
        }

        System.out.println(c);
    }

    public static int find(int[] par, int x) {
        if (par[x] == x) {
            return x;
        } else {
            return find(par, par[x]);
        }
    }

    public static void unite(int[] par, int[] rank, int[] size, int x, int y) {
        x = find(par, x);
        y = find(par, y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                par[x] = y;
                size[y] += size[x];
            } else {
                par[y] = x;
                size[x] += size[y];
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
    }
}
