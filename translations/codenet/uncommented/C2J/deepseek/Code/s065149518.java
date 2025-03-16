public class Robot {
    static int n, x, y;
    static int[][] fld = new int[21][21];

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            if (n == 0) break;
            init(n, scanner);
            int m = scanner.nextInt();
            move(m, scanner);
            System.out.println(n == 0 ? "Yes" : "No");
        }
    }

    static void init(int i, java.util.Scanner scanner) {
        int a, b;
        x = 10;
        y = 10;
        java.util.Arrays.fill(fld, 0);
        while (i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    static void move(int i, java.util.Scanner scanner) {
        int a, d;
        char[] buf = new char[2];
        while (i-- > 0) {
            String dir = scanner.next();
            a = scanner.nextInt();
            switch (dir.charAt(0)) {
                case 'N':
                    d = 0;
                    break;
                case 'E':
                    d = 1;
                    break;
                case 'S':
                    d = 2;
                    break;
                case 'W':
                    d = 3;
                    break;
                default:
                    d = -1;
                    break;
            }
            while (a-- > 0) {
                if (d % 2 == 0) {
                    if (d == 0) x--;
                    else x++;
                } else {
                    if (d == 1) y++;
                    else y--;
                }
                if (fld[y][x] == 1) {
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}
