import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        char[][] grid = new char[h][w];
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                grid[i][j] = sc.next().charAt(0);
                if (grid[i][j] == 's' && j <= w - 5) {
                    if (grid[i][j + 1] == 'n' && grid[i][j + 2] == 'u' && grid[i][j + 3] == 'k' && grid[i][j + 4] == 'e') {
                        char col = (char) ('A' + j);
                        System.out.println(col + "" + (i + 1));
                        return;
                    }
                }
            }
        }
    }
}
