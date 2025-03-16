import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        char[][] l = new char[n][m];

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.') {
                    if ((i + j) % 2 == 0) {
                        l[i][j] = 'B';
                    } else {
                        l[i][j] = 'W';
                    }
                } else {
                    l[i][j] = s.charAt(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(l[i][j]);
            }
            System.out.println();
        }
    }
}

