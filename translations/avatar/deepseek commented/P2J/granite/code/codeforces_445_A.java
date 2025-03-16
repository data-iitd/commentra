

import java.util.Scanner;

public class codeforces_445_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        char[][] grid = new char[n][m];
        for (int i = 0; i < n; i++) {
            String row = scanner.next();
            for (int j = 0; j < m; j++) {
                grid[i][j] = row.charAt(j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if ((i + j) % 2 == 0) {
                        grid[i][j] = 'B';
                    } else {
                        grid[i][j] = 'W';
                    }
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

Translate the above Java code to C++ and end with comment "