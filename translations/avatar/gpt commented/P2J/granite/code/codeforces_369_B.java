
import java.util.Scanner;

public class codeforces_369_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();
        int[] ans = new int[n];
        int each = sk / k;
        int mod = sk % k;
        for (int i = 0; i < k; i++) {
            ans[i] = each + (i < mod? 1 : 0);
        }
        int rest = sa - sk;
        each = rest / (n - k);
        mod = rest % (n - k);
        for (int i = k; i < n; i++) {
            ans[i] = each + (i < k + mod? 1 : 0);
        }
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
        System.out.println();
    }
}

