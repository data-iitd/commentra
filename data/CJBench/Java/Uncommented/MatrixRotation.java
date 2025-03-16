import java.util.Scanner;
public class MatrixRotation {
    public static void rotate(int[][] matrix, int r) {
        int left = 0;
        int up = 0;
        int m = matrix.length;
        int n = matrix[0].length;
        while (m >= 1 && n >= 1) {
            int count = 2 * (m + n) - 4;
            int[] tmp = new int[count];
            int curr = 0;
            for (int i = 0; i < n; i++) {
                tmp[curr] = matrix[up][left + i];
                curr++;
            }
            for (int i = 1; i < m - 1; i++) {
                tmp[curr] = matrix[up + i][left + n - 1];
                curr++;
            }
            for (int i = n - 1; i >= 0; i--) {
                tmp[curr] = matrix[up + m - 1][left + i];
                curr++;
            }
            for (int i = m - 2; i >= 1; i--) {
                tmp[curr] = matrix[up + i][left];
                curr++;
            }
            curr = r % count;
            if (curr < 0) {
                curr += count;
            }
            for (int i = 0; i < n; i++) {
                matrix[up][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = 1; i < m - 1; i++) {
                matrix[up + i][left + n - 1] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                matrix[up + m - 1][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = m - 2; i >= 1; i--) {
                matrix[up + i][left] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            m -= 2;
            n -= 2;
            left++;
            up++;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        int rotations = sc.nextInt();
        rotate(matrix, rotations);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
