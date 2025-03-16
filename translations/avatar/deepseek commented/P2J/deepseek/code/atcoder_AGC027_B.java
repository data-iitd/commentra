import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        List<Integer> A = IntStream.range(0, N).map(i -> scanner.nextInt()).boxed().collect(Collectors.toList());

        // Accumulating sums
        List<Integer> S = new ArrayList<>();
        int sum = 0;
        for (int a : A) {
            sum += a;
            S.add(sum);
        }

        // Initializing answer
        int ans = Integer.MAX_VALUE;

        // Calculating energy
        for (int k = 1; k <= N; k++) {
            int E = k * X + 2 * sum(S, N - 2 * k - 1, -k);
            ans = Math.min(ans, E);
        }

        // Final calculation
        System.out.println(ans + N * X + 5 * S.get(S.size() - 1));
    }

    // Helper method to calculate sum
    private static int sum(List<Integer> list, int start, int step) {
        int sum = 0;
        for (int i = start; i >= 0; i += step) {
            sum += list.get(i);
        }
        return sum;
    }
}
