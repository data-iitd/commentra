
public class Main {
    public static void main(String[] args) {
        int n, r, c, flag, cnt;
        int[][] arr = new int[16][16];

        while (true) {
            System.out.print("Enter the size of the square matrix: ");
            n = sc.nextInt();

            if (n == 0) {
                break;
            }

            flag = 1;
            r = (n + 1) / 2 + 1;
            c = (n + 1) / 2;

            arr[r][c] = cnt = 1;

            while (cnt != n * n + 1) {
                ++cnt;

                if (flag) {
                    ++r;
                    ++c;

                    if (c > n) {
                        c = 1;
                    }

                    if (r > n) {
                        r = 1;
                    }

                    if (arr[r][c]) {
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

                    if (arr[r][c]) {
                        flag = 0;
                    } else {
                        arr[r][c] = cnt;
                        flag = 1;
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

