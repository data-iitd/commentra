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
            b[i + 1] = b[i] + (a[i] >= 0? 1 : -1);
        }
        int c = Math.min(b);
        for (int i = 0; i < n; i++) {
            b[i] -= c;
        }
        int ans = 0;
        for (int x : b) {
            ans += x;
        }
        System.out.println(ans >= m? a[b.length - 1] : -1);
    }
}

