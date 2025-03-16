
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;

        for (int i = 1; i*i < n; i++) {
            if (n%i == 0 && n%(n/i-1) == i) {
                ans += n/i - 1;
            }
        }

        System.out.println(ans);
    }
}

