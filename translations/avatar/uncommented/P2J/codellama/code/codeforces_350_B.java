import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n + 1];
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        int[] ans = new int[n + 1];
        int[] cnt = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {
                int[] crt = new int[n + 1];
                int x = a[i];
                while (cnt[x] == 1) {
                    crt[i] = x;
                    x = a[x];
                }
                if (crt.length > ans.length) {
                    ans = crt;
                }
            }
        }
        for (int i = ans.length - 1; i >= 0; i--) {
            System.out.print(ans[i] + " ");
        }
        System.out.println();
        System.out.println(ans.length);
    }
}

