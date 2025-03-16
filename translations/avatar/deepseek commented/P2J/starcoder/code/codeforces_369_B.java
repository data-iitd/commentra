import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int sa = sc.nextInt();
        int sk = sc.nextInt();

        int[] ans = new int[n];
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = 1;
        }

        for (int i = 0; i < k; i++) {
            nums[i] = l + (r - l) * i / (k - 1);
        }

        for (int i = k; i < n; i++) {
            nums[i] = r + (l - r) * (i - k) / (n - k - 1);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i] * (sa - sk);
        }

        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}

