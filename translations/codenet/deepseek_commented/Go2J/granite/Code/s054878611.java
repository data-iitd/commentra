
import java.util.Scanner;

public class s054878611{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] memo = new int[100002];
        for (int i = 0; i < n; i++) {
            memo[a[i]]++;
            memo[a[i] + 1]++;
            memo[a[i] + 2]++;
        }
        int out = 0;
        for (int i = 0; i < memo.length; i++) {
            if (memo[i] > 0) {
                out = Math.max(out, memo[i]);
            }
        }
        System.out.println(out);
    }
}

// 