import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }

        // Create a new list S by applying the accumulate function to the list A
        List<Integer> S = new ArrayList<>();
        int sum = 0;
        for (int a : A) {
            sum += a;
            S.add(sum);
        }

        // Initialize a variable ans with a large value
        long ans = Long.MAX_VALUE;

        // Iterate through each element s in the list S
        for (int k = 1; k <= N; k++) {
            int s = S.get(k - 1);
            // Calculate the energy consumption E for the current index k
            long E = k * X + 2 * IntStream.range(0, N - 2 * k - 1)
                    .map(j -> S.get(N - j - 1) - S.get(N - 2 * k - 1 - j))
                    .sum();

            // Update the minimum energy consumption ans if the current energy consumption E is smaller
            ans = Math.min(ans, E);
        }

        // Print the result
        System.out.println(ans + N * X + 5 * S.get(S.size() - 1));
    }
}
