import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Integer> h = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            h.add(scanner.nextInt());
        }

        List<Integer> dp = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            dp.add(Integer.MAX_VALUE);
        }
        dp.set(0, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i + j < N) {
                    dp.set(i + j, Math.min(dp.get(i + j), dp.get(i) + Math.abs(h.get(i) - h.get(i + j))));
                }
            }
        }

        System.out.println(dp.get(N - 1));
    }
}
