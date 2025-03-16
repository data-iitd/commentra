import java.util.Scanner;

public class MagicSquare {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        while (true) {
            System.out.print("Enter the size of the square matrix: ");
            n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            int[][] arr = new int[16][16];
            int r = (n + 1) / 2 + 1;
            int c = (n + 1) / 2;
            int cnt = 1;
            boolean flag = true;
            arr[r][c] = cnt;
            while (cnt != n * n + 1) {
                cnt++;
                if (flag) {
                    r++;
                    c++;
                    if (c > n) {
                        c = 1;
                    }
                    if (r > n) {
                        r = 1;
                    }
                    if (arr[r][c] != 0) {
                        flag = false;
                        cnt--;
                    } else {
                        arr[r][c] = cnt;
                    }
                } else {
                    r++;
                    c--;
                    if (c < 1) {
                        c = n;
                    }
                    if (r > n) {
                        r = 1;
                    }
                    if (arr[r][c] != 0) {
                        flag = true;
                    } else {
                        arr[r][c] = cnt;
                        flag = true;
                    }
                }
            }
            for (r = 1; r < n + 1; r++) {
                for (c = 1; c < n + 1; c++) {
                    System.out.printf("%4d", arr[r][c]);
                    arr[r][c] = 0;
                    if (c == n) {
                        System.out.println();
                    }
                }
            }
        }
    }
}
