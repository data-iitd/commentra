import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array and the target sum: ");
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int[] a = new int[100];
        System.out.println("Enter " + n + " integers: ");
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        boolean[] dp = new boolean[k + 1];
        for (int i = 0; i <= k; i++) {
            dp[i] = false;
        }

        for (int i = 1; i <= k; i++) {
            boolean win = false;
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (dp[i - a[j]]) {
                    win = true;
                    break;
                }
            }
            dp[i] = win;
        }

        System.out.print("The target sum " + k + " is ");
        if (dp[k]) {
            System.out.println("First");
        } else {
            System.out.println("Second");
        }
    }
}
