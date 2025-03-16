
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] f1 = new int[100];
        int[] f2 = new int[100];
        while (n > 0) {
            int k = n % 10;
            while (n >= 10) {
                n /= 10;
            }
            f1[10 * k + n]++;
            f2[n * 10 + k]++;
            n--;
        }
        int ans = 0;
        for (int i = 0; i < 100; i++) {
            ans += f1[i] * f2[i];
        }
        System.out.println(ans);
    }
}

