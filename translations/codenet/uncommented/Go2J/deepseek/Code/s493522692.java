import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int tmp = Math.min(N, M / 2);
        int ans = tmp;
        N -= tmp;
        M -= tmp * 2;
        ans += M / 4;
        System.out.println(ans);
    }
}
