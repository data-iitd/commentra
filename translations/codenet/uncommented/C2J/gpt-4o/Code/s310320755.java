import java.util.Scanner;

public class MagicSquare {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int r, c, n, flag, cnt;
        int[][] arr = new int[17][17]; // Using 17 to accommodate 1-based indexing

        while (true) {
            n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            flag = 1;
            r = (n + 1) / 2 + 1;
            c = (n + 1) / 2;
            arr[r][c] = cnt = 1;

            while (cnt != n * n + 1) {
                ++cnt;
                if (flag == 1) {
                    ++r;
                    ++c;
                    if (c > n) {
                        c = 1;
                    }

                    if (r > n) {
                        r = 1;
                    }

                    if (arr[r][c] != 0) {
                        flag = 0;
                        --cnt;
                    } else {
                        arr[r][c] = cnt;
                    }
                } else {
                    ++r;
                    --c;
                    if (c < 1) {
                        c = n;
                    }

                    if (r > n) {
                        r = 1;
                    }

                    if (arr[r][c] != 0) {
                        flag = 0;
                    } else {
                        arr[r][c] = cnt;
                        flag = 1;
                    }
                }

                // Uncomment for debugging
                // System.out.printf("r=%d  c=%d   cnt=%d\n", r, c, cnt);
            }

            for (r = 1; r < n + 1; r++) {
                for (c = 1; c < n + 1; c++) {
                    System.out.printf("%4d", arr[r][c]);
                    arr[r][c] = 0; // Resetting the array for the next input
                    if (c == n) {
                        System.out.println();
                    }
                }
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
