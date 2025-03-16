import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the length of the string and the number of queries
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        // Read the string
        String s = scanner.next();

        // Read the queries
        List<int[]> problems = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            problems.add(new int[]{l, r});
        }

        // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
        List<Integer> cumsum = IntStream.range(0, n)
                .map(i -> s.charAt(i) == 'A' && s.charAt(i + 1) == 'C' ? 1 : 0)
                .boxed()
                .collect(Collectors.toList());

        // Compute the prefix sums
        for (int i = 1; i < cumsum.size(); i++) {
            cumsum.set(i, cumsum.get(i) + cumsum.get(i - 1));
        }

        // Iterate over the queries and print the difference in cumulative sums
        for (int[] query : problems) {
            int l = query[0];
            int r = query[1];
            System.out.println(cumsum.get(r - 1) - cumsum.get(l - 1));
        }
    }
}
