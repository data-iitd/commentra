
import java.util.Scanner;
public final class WineProblem {
    private WineProblem() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int result = wpbu(arr);
        System.out.println("Maximum profit: " + result);
        scanner.close();
    }
    public static int wpbu(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Input array cannot be null or empty.");
        }
        int n = arr.length;
        int[][] strg = new int[n][n];
        for (int slide = 0; slide <= n - 1; slide++) {
            for (int si = 0; si <= n - slide - 1; si++) {
                int ei = si + slide;
                int year = (n - (ei - si + 1)) + 1;
                if (si == ei) {
                    strg[si][ei] = arr[si] * year;
                } else {
                    int start = strg[si + 1][ei] + arr[si] * year;
                    int end = strg[si][ei - 1] + arr[ei] * year;
                    strg[si][ei] = Math.max(start, end);
                }
            }
        }
        return strg[0][n - 1];
    }
}
