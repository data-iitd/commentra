import java.util.Scanner;

public class Main {
    private static final double INF = 10000000000.0;

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

        double ans = INF;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(cumSumA[n] - (cumSumA[i] * 2));
            if (diff < ans) {
                ans = diff;
            }
        }

        System.out.println((int) ans);
        scanner.close();
    }
}

// <END-OF-CODE>
