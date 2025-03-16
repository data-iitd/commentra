
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n + 1];
        int[] a = new int[n + 1];
        int[] cnt = new int[n + 1];
        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
            a[i] = sc.nextInt();
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {
                int x = a[i];
                int j = 0;
                while (cnt[x] == 1) {
                    ans[j++] = x;
                    x = a[x];
                }
                if (j > ans.length) {
                    ans = Arrays.copyOf(ans, j);
                }
            }
        }
        System.out.println(ans.length);
        System.out.println(Arrays.stream(ans).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
    }
}

