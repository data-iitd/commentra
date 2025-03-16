import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: N (number of elements), X (a constant), and A (the list of integers)
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }
        
        // Calculate the cumulative sum of the list A
        List<Integer> S = new ArrayList<>();
        int sum = 0;
        for (int a : A) {
            sum += a;
            S.add(sum);
        }
        
        // Initialize the answer to a very large number (infinity)
        int ans = Integer.MAX_VALUE;
        
        // Iterate through the cumulative sums with an index starting from 1
        for (int k = 1; k <= N; k++) {
            // Calculate the expression E based on the current index k and the cumulative sums
            int E = k * X + 2 * IntStream.range(0, N - 2 * k - 1)
                                        .filter(j -> j % k == 0)
                                        .map(j -> S.get(N - 1 - j))
                                        .sum();
            
            // Update the answer with the minimum value found so far
            ans = Math.min(ans, E);
        }
        
        // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
        System.out.println(ans + N * X + 5 * S.get(S.size() - 1));
    }
}
