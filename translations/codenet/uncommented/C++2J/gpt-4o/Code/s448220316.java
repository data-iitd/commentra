import java.util.Scanner;

public class Main {
    static int n, m, l, r, vi;
    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    static int get(int x) {
        if (x == fa[x]) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        return fa[x] = f;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        
        for (int i = 1; i <= m; i++) {
            l = scanner.nextInt();
            r = scanner.nextInt();
            vi = scanner.nextInt();
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
// <END-OF-CODE>
