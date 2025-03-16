import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        int ans = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int tmp = scanner.nextInt();
            X -= tmp;
            ans++;
            if (tmp < min) min = tmp;
        }

        ans += X / min;

        System.out.println(ans);
    }
}
