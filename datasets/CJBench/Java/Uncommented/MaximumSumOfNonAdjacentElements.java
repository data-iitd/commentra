
import java.util.Scanner;
final class MaximumSumOfNonAdjacentElements {
    private MaximumSumOfNonAdjacentElements() {
    }
    public static int getMaxSumApproach1(int[] arr) {
        if (arr.length == 0) {
            return 0; 
        }
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = arr[0];
        for (int ind = 1; ind < n; ind++) {
            int notTake = dp[ind - 1];
            int take = arr[ind];
            if (ind > 1) {
                take += dp[ind - 2];
            }
            dp[ind] = Math.max(take, notTake);
        }
        return dp[n - 1];
    }
    public static int getMaxSumApproach2(int[] arr) {
        if (arr.length == 0) {
            return 0; 
        }
        int n = arr.length;
        int prev1 = arr[0];
        int prev2 = 0;
        for (int ind = 1; ind < n; ind++) {
            int notTake = prev1;
            int take = arr[ind];
            if (ind > 1) {
                take += prev2;
            }
            int current = Math.max(take, notTake);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int choice = scanner.nextInt();
        int result;
        if (choice == 1) {
            result = getMaxSumApproach1(array);
        } else {
            result = getMaxSumApproach2(array);
        }
        System.out.println("The maximum sum of non-adjacent elements is: " + result);
    }
}
