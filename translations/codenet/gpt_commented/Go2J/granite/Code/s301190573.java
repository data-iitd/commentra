
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s301190573{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int[] p = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] par = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < m; i++) {
            s = br.readLine().split(" ");
            int x = Integer.parseInt(s[0]) - 1;
            int y = Integer.parseInt(s[1]) - 1;
            unite(par, rank, x, y);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (same(par, i, p[i])) {
                count++;
            }
        }
        System.out.println(count);
    }

    public static void initialize(int[] par, int n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    public static int root(int[] par, int i) {
        if (par[i] == i) {
            return i;
        }
        par[i] = root(par, par[i]);
        return par[i];
    }

    public static boolean same(int[] par, int i, int j) {
        return root(par, i) == root(par, j);
    }

    public static void unite(int[] par, int[] rank, int i, int j) {
        int x = root(par, i);
        int y = root(par, j);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
}

