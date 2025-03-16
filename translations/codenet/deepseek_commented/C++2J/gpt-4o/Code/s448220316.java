import java.io.*;

public class Main {
    static int n, m, l, r, vi;
    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    // Read function to efficiently read integers.
    static int read() throws IOException {
        int k = 0, f = 1;
        char ch = (char) System.in.read();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = (char) System.in.read();
        }
        while (ch >= '0' && ch <= '9') {
            k = k * 10 + ch - '0';
            ch = (char) System.in.read();
        }
        return k * f;
    }

    // Write function to efficiently write integers.
    static void write(int x) {
        if (x < 0) {
            x = -x;
            System.out.print('-');
        }
        if (x > 9) write(x / 10);
        System.out.print((char) (x % 10 + '0'));
    }

    // Writeln function to write integers and print a newline.
    static void writeln(int x) {
        write(x);
        System.out.println();
    }

    // Get function to find the root of a node and update the value array.
    static int get(int x) {
        if (x == fa[x]) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        return fa[x] = f;
    }

    public static void main(String[] args) throws IOException {
        n = read();
        m = read();
        for (int i = 1; i <= n; i++) fa[i] = i;

        for (int i = 1; i <= m; i++) {
            l = read();
            r = read();
            vi = read();
            int li = get(l), ri = get(r);
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
// <END-OF-CODE>
