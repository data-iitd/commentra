import java.util.*;

public class MagicSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        int r = (n + 1) / 2 + 1;
        int c = (n + 1) / 2;
        int cnt = 1;
        arr[r][c] = cnt;
        int flag = 1;
        while (cnt!= n*n + 1) {
            cnt++;
            if (flag) {
                r++;
                c++;
                if (c > n) c = 1;
                if (r > n) r = 1;
                if (arr[r][c]!= 0) {
                    flag = 0;
                    cnt--;
                } else {
                    arr[r][c] = cnt;
                }
            } else {
                r++;
                c--;
                if (c < 1) c = n;
                if (r > n) r = 1;
                if (arr[r][c]!= 0) {
                    flag = 0;
                } else {
                    arr[r][c] = cnt;
                    flag = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
