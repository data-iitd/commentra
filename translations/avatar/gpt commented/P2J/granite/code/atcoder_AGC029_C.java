
import java.util.*;

public class atcoder_AGC029_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] dp = new int[n];
        int[] cut = new int[n];
        int[] cut_index = new int[n];
        int[] cut_value = new int[n];
        int k = 0;
        int index = 0;
        int value = 0;
        int count = 0;
        int max_k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= a[index]) {
                cut[count] = index;
                cut_index[count] = i;
                cut_value[count] = a[i];
                count++;
            } else {
                index = i;
                count = 0;
                cut[count] = index;
                cut_index[count] = i;
                cut_value[count] = a[i];
                count++;
            }
            dp[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] < k - 1) {
                for (int j = 0; j < count; j++) {
                    if (cut_value[j] < a[i]) {
                        dp[i] = dp[cut[j]] + 1;
                        cut_index[j] = i;
                        break;
                    }
                }
            }
            if (dp[i] >= k - 1) {
                max_k = Math.max(max_k, k);
            }
            if (dp[i] == k - 1) {
                k++;
            }
        }
        System.out.println(max_k);
    }
}

Translate the above Java code to C++ and end with comment "