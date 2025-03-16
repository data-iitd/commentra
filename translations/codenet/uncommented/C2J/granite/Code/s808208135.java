
import java.util.Scanner;

public class s808208135{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] d = new int[n];
        int count = 0;
        int[][] a = new int[500000][3];
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt();
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                a[count][1] = u;
                a[count][0] = scanner.nextInt();
                a[count][2] = scanner.nextInt();
                count++;
            }
        }
        root(a, count);
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }

    public static void root(int[][] a, int b) {
        int i, flag = 1;

        for (i = 0; i < a.length; i++) {
            d[i] = 1000000;
        }
        d[0] = 0;

        while (flag!= 0) {
            flag = 0;
            for (i = 0; i < b; i++) {
                if (a[i][2] + d[a[i][1]] < d[a[i][0]]) {
                    d[a[i][0]] = a[i][2] + d[a[i][1]];
                    flag = 1;
                }
            }
        }
    }
}

