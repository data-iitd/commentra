
import java.util.*;

public class atcoder_AGC027_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                System.out.println(ans);
                return;
            }
            x -= a[i];
            ans++;
        }
        if (x!= 0) {
            ans--;
        }
        System.out.println(ans);
    }
}
