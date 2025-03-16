import java.util.Scanner;

public class Main {
    static int[] f1 = new int[100];
    static int[] f2 = new int[100];

    static void calc(int n) {
        int k = n % 10;
        while (n >= 10) n /= 10;
        f1[10 * k + n]++;
        f2[n * 10 + k]++;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        while (N > 0) {
            calc(N);
            N--;
        }

        int ans = 0;
        for (int i = 0; i < 100; i++) {
            ans += f1[i] * f2[i];
        }
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
