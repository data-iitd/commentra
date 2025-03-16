
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] grid = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.') {
                    if ((i + j) % 2 == 1) {
                        grid[i][j] = 'W';
                    } else {
                        grid[i][j] = 'B';
                    }
                } else {
                    grid[i][j] = s.charAt(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}

