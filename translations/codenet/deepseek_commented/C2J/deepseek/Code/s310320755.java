public class MagicSquare {
    public static void main(String[] args) {
        int n, flag, cnt;
        int[][] arr = new int[16][16];

        while (true) {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            n = scanner.nextInt();
            if (n == 0) {
                break;
            }

            flag = 1;
            int r = (n + 1) / 2;
            int c = (n + 1) / 2 - 1;
            arr[r][c] = cnt = 1;

            while (cnt != n * n + 1) {
                ++cnt;
                if (flag == 1) {
                    ++r;
                    ++c;
                    if (c == n) c = 0;
                    if (r == n) r = 0;
                    if (arr[r][c] != 0) {
                        flag = 0;
                        --cnt;
                    } else {
                        arr[r][c] = cnt;
                    }
                } else {
                    --r;
                    --c;
                    if (c == -1) c = n - 1;
                    if (r == -1) r = n - 1;
                    if (arr[r][c] != 0) {
                        flag = 1;
                    } else {
                        arr[r][c] = cnt;
                        flag = 1;
                    }
                }
            }

            for (r = 0; r < n; r++) {
                for (c = 0; c < n; c++) {
                    System.out.printf("%4d", arr[r][c]);
                    arr[r][c] = 0;
                }
                System.out.println();
            }
        }
    }
}
