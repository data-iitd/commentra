public class GoldbachConjecture {
    static int[] flag;

    public static void prime(int num) {
        flag = new int[num + 1];
        for (int i = 2; i * i <= num; i++) {
            if (flag[i] == 0) {
                for (int j = 2; i * j <= num; j++) {
                    flag[i * j] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
