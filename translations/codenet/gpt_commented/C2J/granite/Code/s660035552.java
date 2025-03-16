
import java.util.Scanner;

public class s660035552{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }
        int[] low = new int[200000];
        int[] high = new int[200000];
        int[] c = new int[200000];
        int sp = 0;
        low[sp] = 0;
        high[sp] = m - 1;
        int cnt = 0;
        int t = 0;
        while (sp >= 0) {
            int l = low[sp];
            int r = high[sp];
            sp--;
            if (l >= r) continue;
            int v = part(a, b, c, l, r);
            if (v - l < r - v) {
                low[sp] = v + 1;
                high[sp++] = r;
                low[sp] = l;
                high[sp++] = v - 1;
            } else {
                low[sp] = l;
                high[sp++] = v - 1;
                low[sp] = v + 1;
                high[sp++] = r;
            }
        }
        System.out.println(cnt);
    }

    public static int part(int[] a, int[] b, int[] c, int l, int r) {
        int i, j, x, t;
        i = l - 1;
        j = r;
        x = b[r];
        while (true) {
            while (b[++i] < x);
            while (i < --j && x < b[j]);
            if (i >= j) break;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            t = b[i];
            b[i] = b[j];
            b[j] = t;
            t = c[i];
            c[i] = c[j];
            c[j] = t;
        }
        t = a[i];
        a[i] = a[r];
        a[r] = t;
        t = b[i];
        b[i] = b[r];
        b[r] = t;
        t = c[i];
        c[i] = c[r];
        c[r] = t;
        return i;
    }
}

