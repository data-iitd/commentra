
import java.util.Arrays;
import java.util.Scanner;

public class s032857139{
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (x >= a[i]) {
                ans++;
                x -= a[i];
                i++;
            } else {
                j++;
            }
        }
        if (x > 0 && n == ans) {
            ans--;
        }
        System.out.println(ans);
    }
}
