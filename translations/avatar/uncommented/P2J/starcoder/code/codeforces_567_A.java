import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();
        int[] dp = new int[n];
        dp[0] = arr[1] - arr[0];
        dp[n-1] = arr[n-1] - arr[n-2];
        for(int i=1;i<n-1;i++)
            dp[i] = Math.max(dp[i-1],arr[i+1]-arr[i]);
        for(int i=0;i<n-1;i++)
            System.out.print(dp[i]+" ");
        System.out.println();
        for(int i=n-1;i>0;i--)
            System.out.print(dp[i-1]+" ");
        System.out.println();
    }
}
