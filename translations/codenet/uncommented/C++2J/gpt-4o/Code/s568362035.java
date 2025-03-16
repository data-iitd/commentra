import java.util.Scanner;

public class Main {
    static final int MAXN = (int) 1E5 + 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int Q = scanner.nextInt();
        
        int[] a = new int[Q + 1];
        int[] b = new int[MAXN];
        int[] id = new int[MAXN];
        boolean[] vis = new boolean[MAXN];
        int[] cnt = new int[MAXN];

        for (int i = 1; i <= Q; ++i) {
            a[i] = scanner.nextInt();
        }

        int k = 0;
        for (int j = Q; j > 0; --j) {
            if (!vis[a[j]]) {
                b[++k] = a[j];
                vis[a[j]] = true;
            }
        }

        for (int j = m, i = m; i > 0; --i) {
            if (!vis[i]) {
                b[j--] = i;
            }
        }

        for (int i = 1; i <= m; ++i) {
            id[b[i]] = i;
        }

        boolean flag = true;
        cnt[0] = n;
        for (int i = Q; i > 0; --i) {
            int t = id[a[i]];
            if (cnt[t - 1] > 0) {
                --cnt[t - 1];
                ++cnt[t];
                vis[t] = true;
            } else if (!vis[t]) {
                flag = false;
                break;
            }
        }

        int l;
        for (l = 0; cnt[l] == 0; ++l);
        for (int i = l + 1; i < m; ++i) {
            flag &= b[i] < b[i + 1];
        }

        System.out.println(flag ? "Yes" : "No");
        scanner.close();
    }
}
// <END-OF-CODE>
