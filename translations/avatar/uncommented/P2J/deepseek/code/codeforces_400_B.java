import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            String row = scanner.next();
            for (int j = 0; j < m; j++) {
                grid[i][j] = row.charAt(j);
            }
        }

        int[] distances = new int[n];
        for (int i = 0; i < n; i++) {
            int sIndex = -1;
            int gIndex = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') {
                    sIndex = j;
                } else if (grid[i][j] == 'G') {
                    gIndex = j;
                }
            }
            if (sIndex == -1 || gIndex == -1 || sIndex > gIndex) {
                System.out.println(-1);
                return;
            }
            distances[i] = gIndex - sIndex;
        }

        int uniqueDistances = 0;
        boolean hasNegativeDistance = false;
        for (int distance : distances) {
            if (distance < 0) {
                hasNegativeDistance = true;
                break;
            }
            if (distance > 0) {
                uniqueDistances++;
            }
        }

        if (hasNegativeDistance) {
            System.out.println(-1);
        } else {
            System.out.println(uniqueDistances);
        }
    }
}
