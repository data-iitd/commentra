

import java.util.Scanner;

public class s283266035{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                if (n % (n / i - 1) == i) {
                    ans += n / i - 1;
                }
            }
        }
        System.out.println(ans);
    }
}

