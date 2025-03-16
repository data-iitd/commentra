
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] s = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s[i][j] = sc.nextInt();
            }
        }
        int flag = 0;
        int[] d1 = new int[n];
        int[] d2 = new int[n];
        int[] rem = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1[i] = s[i][j];
                }
                if (i == n - j - 1) {
                    d2[i] = s[i][j];
                }
                if (i != j && i != n - j - 1) {
                    rem[i] = s[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d1[i] != d2[i]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}

