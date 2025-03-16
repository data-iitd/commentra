import java.util.Scanner;

public class Main {
    static class FenwickTree {
        private int n;
        private int[] data;

        public FenwickTree(int n) {
            this.n = n;
            this.data = new int[n];
        }

        public void add(int p, int x) {
            p++;
            while (p <= n) {
                data[p - 1] += x;
                p += p & -p;
            }
        }

        public int sum(int l, int r) {
            return sum(r) - sum(l);
        }

        private int sum(int r) {
            int s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();

        FenwickTree fw = new FenwickTree(n);
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            fw.add(i, a);
        }

        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 0) {
                int p = sc.nextInt();
                int x = sc.nextInt();
                fw.add(p, x);
            } else {
                int l = sc.nextInt();
                int r = sc.nextInt();
                System.out.println(fw.sum(l, r));
            }
        }
        sc.close();
    }
}

// <END-OF-CODE>
