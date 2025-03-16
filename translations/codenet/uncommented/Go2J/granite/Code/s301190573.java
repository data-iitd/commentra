
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s301190573{
    static int size = 1000000;
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), size);
    static StringTokenizer tokenizer = new StringTokenizer("");

    public static String NextLine() throws IOException {
        tokenizer = new StringTokenizer("");
        return reader.readLine();
    }

    public static int NextInt() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(NextLine());
        }
        return Integer.parseInt(tokenizer.nextToken());
    }

    public static int[] NextIntArray() throws IOException {
        String[] s = NextLine().split(" ");
        int[] a = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            a[i] = Integer.parseInt(s[i]) - 1;
        }
        return a;
    }

    static int[] par;
    static int[] rank;

    public static void main(String[] args) throws IOException {
        int n = NextInt();
        int m = NextInt();
        int[] p = NextIntArray();
        initialize(n);
        for (int i = 0; i < m; i++) {
            int x = NextInt() - 1;
            int y = NextInt() - 1;
            unite(x, y);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i])) {
                s++;
            }
        }
        System.out.println(s);
    }

    public static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    public static int root(int i) {
        if (par[i] == i) {
            return i;
        }
        par[i] = root(par[i]);
        return par[i];
    }

    public static boolean same(int i, int j) {
        return root(i) == root(j);
    }

    public static void unite(int i, int j) {
        int x = root(i);
        int y = root(j);
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
