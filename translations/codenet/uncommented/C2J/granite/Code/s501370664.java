
import java.util.Scanner;

public class s501370664{
    static int[] flag;

    public static void prime(int num) {
        int i, j;

        flag = new int[num + 1];

        for (i = 2; i * i <= num; i++) {
            if (flag[i] == 0) {
                for (j = 2; i * j <= num; j++) {
                    flag[i * j] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, i, cnt;

        prime(50000);

        while (true) {
            n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            i = 2;
            cnt = 0;
            while (i * 2 <= n) {
                if (flag[i] == 0 && flag[n - i] == 0) {
                    cnt++;
                }
                i++;
            }
            System.out.println(cnt);
        }
    }
}

