import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long X = scanner.nextLong();

        long ans = 0;
        long min = Long.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            long tmp = scanner.nextLong();
            X -= tmp;
            ans++;
            if (tmp < min) min = tmp;
        }

        ans += X / min;

        System.out.println(ans);
    }
}
