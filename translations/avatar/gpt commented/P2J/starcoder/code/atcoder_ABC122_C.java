import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of characters in the string and the number of queries
        int n = sc.nextInt();
        int q = sc.nextInt();

        // Read the input string
        String s = sc.next();

        // Read the queries, each containing two integers l and r
        List<List<Integer>> problems = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            problems.add(Arrays.asList(sc.nextInt(), sc.nextInt()));
        }

        // Define a function to count occurrences of 'AC' in the string
        Function<Integer, Integer> count = (i) -> {
            // Increment total if the substring from index i-1 to i is 'AC'
            return s.substring(i - 1, i + 1).equals("AC")? 1 : 0;
        };

        // Create a cumulative sum list to keep track of 'AC' occurrences
        List<Integer> cumsum = new ArrayList<>();
        cumsum.add(0);
        for (int i = 1; i <= n; i++) {
            cumsum.add(cumsum.get(i - 1) + count.apply(i));
        }

        // Process each query to find the number of 'AC' occurrences in the specified range
        for (List<Integer> problem : problems) {
            // Output the difference in cumulative sums to get the count in the range [l, r]
            System.out.println(cumsum.get(problem.get(1) - 1) - cumsum.get(problem.get(0) - 1));
        }
    }
}

