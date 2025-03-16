
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] m = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (m[i][1] < m[j][1]) {
                    int[] temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;
                }
            }
        }
        int a = m[0][1];
        for (int i = 1; i < n; i++) {
            if (m[i][1] > a) {
                System.out.println("Happy Alex");
                break;
            }
            a = m[i][1];
        }
        if (i == n) {
            System.out.println("Poor Alex");
        }
    }
}

