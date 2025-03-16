
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
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (m[j][1] < m[j + 1][1]) {
                    int[] temp = m[j];
                    m[j] = m[j + 1];
                    m[j + 1] = temp;
                }
            }
        }
        int[] a = m[0];
        for (int i = 1; i < n; i++) {
            if (m[i][1] > a[1]) {
                System.out.println("Happy Alex");
                break;
            }
            a = m[i];
        }
        if (i == n) {
            System.out.println("Poor Alex");
        }
    }
}

