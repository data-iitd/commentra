

import java.util.Scanner;

public class codeforces_569_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int s = scanner.nextInt();
        int q = scanner.nextInt();
        int ans = 0;
        while (s < t) {
            s *= q;
            ans += 1;
        }
        System.out.println(ans);
    }
}
// End of code