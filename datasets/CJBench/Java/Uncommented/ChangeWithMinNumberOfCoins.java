import java.util.Arrays;
import java.util.Scanner;
public class ChangeWithMinNumberOfCoins {
    public static int determineUsingRecursion(int[] coins, int amount) {
        Arrays.sort(coins);
        var result = innerRecursion(coins, amount);
        if (result == Integer.MAX_VALUE) {
            return -1;
        }
        return result;
    }
    private static int innerRecursion(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int result = Integer.MAX_VALUE;
        for (var coin : coins) {
            if (amount >= coin) {
                int subResult = innerRecursion(coins, amount - coin);
                if (subResult != Integer.MAX_VALUE && subResult + 1 < result) {
                    result = subResult + 1;
                }
            }
        }
        return result;
    }
    public static int determineUsingMemoization(int[] coins, int amount) {
        int[] minCoins = new int[amount + 1];
        Arrays.fill(minCoins, Integer.MAX_VALUE);
        minCoins[0] = 0;
        Arrays.sort(coins);
        for (int i = 1; i <= amount; i++) {
            for (var coin : coins) {
                if (i - coin >= 0) {
                    int subResult = minCoins[i - coin];
                    if (subResult != Integer.MAX_VALUE && subResult + 1 < minCoins[i]) {
                        minCoins[i] = subResult + 1;
                    }
                }
            }
        }
        if (minCoins[amount] == Integer.MAX_VALUE) {
            return -1;
        }
        return minCoins[amount];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] coins = new int[n];
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }
        int amount = sc.nextInt();
        System.out.println("Minimum coins required (Recursion): " + determineUsingRecursion(coins, amount));
        System.out.println("Minimum coins required (Memoization): " + determineUsingMemoization(coins, amount));
        sc.close();
    }
}
