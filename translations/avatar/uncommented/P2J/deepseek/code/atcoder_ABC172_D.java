import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long ans = 0;
        for (int i = 1; i <= N; i++) {
            int div = N / i;
            ans += i * div * (div + 1) / 2;
        }
        System.out.println(ans);
    }
}
