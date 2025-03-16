import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] dp = new int[k + 1];
        for(int i = 1; i <= k; i++) {
            int win = 0;
            for(int j = 0; j < n && a[j] <= i; j++) {
                if(dp[i - a[j]] == 0) {
                    win = 1;
                }
            }
            dp[i] = win;
        }
        System.out.println(dp[k]? "First" : "Second");
    }
}
