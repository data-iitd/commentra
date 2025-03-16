
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int pre = Integer.MAX_VALUE;
        int ans = 0;
        for (int j = n - 1; j >= 0; j--) {
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        System.out.println(ans);
    }
}

