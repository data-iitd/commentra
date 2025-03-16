import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        int aPrev = 0;

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a > i || a > aPrev + 1) {
                System.out.println(-1);
                return;
            }
            if (a == aPrev + 1) {
                ans++;
            } else {
                ans += a;
            }
            aPrev = a;
        }
        System.out.println(ans);
    }
}

