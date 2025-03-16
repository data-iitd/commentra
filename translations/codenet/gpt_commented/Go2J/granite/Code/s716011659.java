
import java.util.Scanner;

public class s716011659{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arrA = new int[n];
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt();
        }
        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0;
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            int diff = Math.abs(cumSumA[n] - cumSumA[i] * 2);
            if (diff < ans) {
                ans = diff;
            }
        }
        System.out.println(ans);
    }
}
