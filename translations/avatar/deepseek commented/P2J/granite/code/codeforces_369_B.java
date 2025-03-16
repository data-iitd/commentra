
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
        scanner.close();

        int[] ans = new int[n];
        int base = sk / k;
        int mod = sk % k;
        for (int i = 0; i < k; i++) {
            ans[i] = base + (i < mod? 1 : 0);
        }
        base = (sa - sk) / (n - k);
        mod = (sa - sk) % (n - k);
        for (int i = k; i < n; i++) {
            ans[i] = base + (i < k + mod? 1 : 0);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(ans[i]).append(' ');
        }
        System.out.println(sb.toString());
    }
}

