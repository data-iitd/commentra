import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;

        a = scanner.nextInt();
        b = scanner.nextInt();
        while (a != 0 && b != 0) {
            kansu(a, b, scanner);
            a = scanner.nextInt();
            b = scanner.nextInt();
        }
        scanner.close();
    }

    public static void kansu(int a, int b, Scanner scanner) {
        int i, j, x, y, n;
        int[][] suu = new int[17][17];
        int[][] kouji = new int[17][17];

        n = scanner.nextInt();
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++) {
                kouji[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            kouji[x][y] = 1;
        }
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++) {
                if (kouji[i][j] == 1) {
                    suu[i][j] = 0;
                } else {
                    if (i == 1 && j == 1) {
                        suu[i][j] = 1;
                    } else {
                        if (i == 1) {
                            suu[i][j] = suu[i][j - 1];
                        } else if (j == 1) {
                            suu[i][j] = suu[i - 1][j];
                        } else {
                            suu[i][j] = suu[i][j - 1] + suu[i - 1][j];
                        }
                    }
                }
            }
        }
        System.out.println(suu[a][b]);
    }
}
// <END-OF-CODE>
