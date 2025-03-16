
import java.util.Scanner;

public class s480530100{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        FenwickTree fw = new FenwickTree(n);
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            fw.add(i, a);
        }
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (t == 0) {
                int p = scanner.nextInt();
                int x = scanner.nextInt();
                fw.add(p, x);
            } else {
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                System.out.println(fw.sum(l, r));
            }
        }
    }
}

class FenwickTree {
    private int n;
    private int[] data;

    public FenwickTree(int n) {
        this.n = n;
        this.data = new int[n];
    }

    public void add(int p, int x) {
        p++; // Convert to 1-based index
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    private int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }
}

// 