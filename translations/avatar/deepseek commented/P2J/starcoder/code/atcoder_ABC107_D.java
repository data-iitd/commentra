import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n * (n + 1) / 4;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            b[a[i]]++;
        }
        int[] c = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            c[i] = c[i - 1] + b[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[a[i]] - i;
        }
        System.out.println(ans >= m? a[n / 2] : -1);
    }
}

