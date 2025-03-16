
import java.util.Scanner;

class s962042834 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 0 && b == 0) {
                break;
            }
            kansu(a, b, sc);
        }
    }

    static void kansu(int a, int b, Scanner sc) {
        int n = sc.nextInt();
        int[][] kouji = new int[a + 1][b + 1];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            kouji[x][y] = 1;
        }
        int[][] suu = new int[a + 1][b + 1];
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
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
