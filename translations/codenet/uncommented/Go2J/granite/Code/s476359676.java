
import java.util.Scanner;

public class s476359676{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int ans = 0;
        int aPrev = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            switch (true) {
                case a > i || a > aPrev + 1:
                    System.out.println(-1);
                    return;
                case a == aPrev + 1:
                    ans++;
                    break;
                default:
                    ans += a;
            }
            aPrev = a;
        }
        System.out.println(ans);
    }
}
