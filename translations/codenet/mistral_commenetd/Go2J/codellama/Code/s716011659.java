
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arrA = new int[n];
        for (int i = 0; i < n; i++) {
            arrA[i] = sc.nextInt();
        }
        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0;
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }
        double ans = 1e12;
        for (int i = 1; i < n; i++) {
            double temp = cumSumA[n] - 2 * cumSumA[i];
            if (Math.abs(temp) < ans) {
                ans = temp;
            }
        }
        System.out.println((int) ans);
    }
}

