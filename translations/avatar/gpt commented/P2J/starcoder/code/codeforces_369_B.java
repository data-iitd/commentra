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

        int[] ans = new int[k + n - k];
        int[] nums = new int[k];
        for (int i = 0; i < k; i++) {
            nums[i] = (sa - sk) / (n - k) + 1;
            if (i < sa % (n - k)) {
                nums[i]++;
            }
        }
        System.arraycopy(nums, 0, ans, 0, k);
        for (int i = 0; i < n - k; i++) {
            ans[i + k] = (sa - sk) / (n - k);
        }
        System.out.println(Arrays.toString(ans));
    }
}

