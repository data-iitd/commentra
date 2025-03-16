
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] m = new int[n][2];
        for (int i = 0; i < n; i++) {
            m[i][0] = sc.nextInt();
            m[i][1] = sc.nextInt();
        }
        int[][] sorted = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][1] > m[j][1]) {
                    sorted[i][0] = m[i][0];
                    sorted[i][1] = m[i][1];
                }
            }
        }
        int[] a = sorted[0];
        for (int i = 1; i < n; i++) {
            if (sorted[i][1] > a[1]) {
                System.out.println("Happy Alex");
                break;
            }
            a = sorted[i];
        }
        if (i == n) {
            System.out.println("Poor Alex");
        }
    }
}

