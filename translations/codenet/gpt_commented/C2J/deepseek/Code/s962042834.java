public class GridPaths {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a == 0 && b == 0) {
                break;
            }
            kansu(a, b, scanner);
        }
    }

    public static void kansu(int a, int b, java.util.Scanner scanner) {
        int[][] suu = new int[17][17];
        int[][] kouji = new int[17][17];
        int n = scanner.nextInt();

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                kouji[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            kouji[x][y] = 1;
        }

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
