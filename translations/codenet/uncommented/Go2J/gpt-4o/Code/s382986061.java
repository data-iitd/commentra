import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        Map<Integer, Integer> as = new HashMap<>();

        for (int i = 1; i <= N; i++) {
            as.put(i, 0);
        }

        for (int i = 0; i < K; i++) {
            int d = scanner.nextInt();
            for (int j = 0; j < d; j++) {
                int a = scanner.nextInt();
                as.put(a, as.get(a) + 1);
            }
        }

        int ans = 0;
        for (int v : as.values()) {
            if (v == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

// <END-OF-CODE>
