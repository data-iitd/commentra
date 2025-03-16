import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        while (scanner.hasNextInt()) {
            A.add(scanner.nextInt());
        }

        List<Integer> S = new ArrayList<>();
        int sum = 0;
        for (int a : A) {
            sum += a;
            S.add(sum);
        }

        int ans = Integer.MAX_VALUE;
        for (int k = 1; k <= N; k++) {
            int E = k * X + 2 * sum(S, N - 2 * k - 1, -1, k);
            ans = Math.min(ans, E);
        }

        System.out.println(ans + N * X + 5 * S.get(S.size() - 1));
    }

    private static int sum(List<Integer> list, int start, int end, int step) {
        int sum = 0;
        for (int i = start; i != end; i += step) {
            sum += list.get(i);
        }
        return sum;
    }
}
