import java.util.*;

public class Main {
    static class FastScanner {
        private Scanner scanner = new Scanner(System.in);

        public int readInt() {
            int k = 0, f = 1;
            char ch = scanner.next().charAt(0);
            while (ch < '0' || ch > '9') {
                if (ch == '-') f = -1;
                ch = scanner.next().charAt(0);
            }
            while (ch >= '0' && ch <= '9') {
                k = k * 10 + ch - '0';
                ch = scanner.next().charAt(0);
            }
            return k * f;
        }

        public void write(int x) {
            if (x < 0) {
                x = -x;
                System.out.print("-");
            }
            if (x > 9) write(x / 10);
            System.out.print(x % 10);
        }

        public void writeln(int x) {
            write(x);
            System.out.println();
        }
    }

    static int[] fa, v;

    static int get(int x) {
        if (x == fa[x]) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        return fa[x] = f;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.readInt();
        int m = fs.readInt();
        fa = new int[n + 1];
        v = new int[2 * n + 1];
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 0; i < m; i++) {
            int l = fs.readInt();
            int r = fs.readInt();
            int vi = fs.readInt();
            int li = get(l);
            int ri = get(r);
            if (li != ri) {
                v[ri] = vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                if (v[r] - v[l] != vi) {
                    System.out.println("No");
                    return;
                }
            }
        }
        System.out.println("Yes");
    }
}
