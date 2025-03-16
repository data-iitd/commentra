import java.util.Scanner;

public class Main {
    static final int MAX = 21;
    static int n, x, y;
    static char[][] fld = new char[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            n = scanner.nextInt();
            if (n == 0) break;
            init(n, scanner);
            int m = scanner.nextInt();
            move(m, scanner);
            System.out.println(n > 0 ? "No" : "Yes");
        }
        scanner.close();
    }

    static void init(int i, Scanner scanner) {
        int a, b;
        x = y = 10;
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                fld[j][k] = 0;
            }
        }
        while (i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    static void move(int i, Scanner scanner) {
        int a, d;
        while (i-- > 0) {
            String buf = scanner.next();
            a = scanner.nextInt();
            switch (buf.charAt(0)) {
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
                    continue;
            }
            while (a-- > 0) {
                if (d % 2 == 1) {
                    if (d == 1) x++; // East
                    else x--; // West
                } else {
                    if (d == 0) y--; // North
                    else y++; // South
                }
                if (fld[y][x] == 1) {
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}
// <END-OF-CODE>
