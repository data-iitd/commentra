import java.util.Scanner;

public class Main {
    static int[] low = new int[200000];
    static int[] high = new int[200000];
    
    public static int part(int[] a, int[] b, int l, int r) {
        int i = l - 1;
        int j = r;
        int x = b[r];
        int t;

        while (true) {
            while (b[++i] < x);
            while (i < --j && x < b[j]);

            if (i >= j) break;

            t = a[i]; a[i] = a[j]; a[j] = t;
            t = b[i]; b[i] = b[j]; b[j] = t;
        }

        t = a[i]; a[i] = a[r]; a[r] = t;
        t = b[i]; b[i] = b[r]; b[r] = t;
        return i;
    }

    public static void quicksort(int[] a, int[] b, int n) {
        int l, r, v;
        int sp = 1;

        low[0] = 0;
        high[0] = n - 1;

        while (sp > 0) {
            sp--;
            l = low[sp];
            r = high[sp];

            if (l >= r) continue;

            v = part(a, b, l, r);

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
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int cnt = 0;
        int t = 0;

        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        quicksort(a, b, m);

        for (int i = 0; i < m; i++) {
            if (t <= a[i]) {
                t = b[i];
                cnt++;
            }
        }

        System.out.println(cnt);
        scanner.close();
    }
}
// <END-OF-CODE>
