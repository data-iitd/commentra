import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Initialize a list to store the input values and a list for prefix sums
        List<Long> a = new ArrayList<>();
        List<Long> acc = new ArrayList<>(Collections.nCopies(n + 1, 0L));

        // Read input values and compute prefix sums modulo MOD
        for (int i = 0; i < n; i++) {
            long value = scanner.nextLong();
            a.add(value);
            acc.set(i + 1, acc.get(i) + value); // Update prefix sum
            acc.set(i + 1, acc.get(i + 1) % 1000000007); // Ensure the prefix sum is within MOD
        }

        // Initialize the answer variable
        long ans = 0;

        // Calculate the final answer using the prefix sums
        for (int i = 0; i < n; i++) {
            ans += a.get(i) % 1000000007 * (1000000007 + acc.get(n) - acc.get(i + 1)) % 1000000007; // Update answer based on current element and remaining sum
            ans %= 1000000007; // Ensure the answer is within MOD
        }

        // Output the final result
        System.out.println(ans);
    }
}

