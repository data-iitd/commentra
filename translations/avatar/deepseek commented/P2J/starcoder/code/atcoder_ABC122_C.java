
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the length of the string and the number of queries
        int n = sc.nextInt();
        int q = sc.nextInt();

        // Read the string
        String s = sc.next();

        // Read the queries
        List<List<Integer>> problems = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            problems.add(Arrays.asList(sc.nextInt(), sc.nextInt()));
        }

        // Define a function to count occurrences of 'AC' in the string
        Function<Integer, Integer> count = (i) -> {
            // Check if the current substring is 'AC'
            if (s.substring(i - 1, i + 1).equals("AC")) {
                // Increment the count if 'AC' is found
                return 1;
            } else {
                // Return the total count if 'AC' is not found
                return 0;
            }
        };

        // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
        List<Integer> cumsum = new ArrayList<>();
        cumsum.add(0);
        for (int i = 1; i <= n; i++) {
            cumsum.add(cumsum.get(i - 1) + count.apply(i));
        }

        // Iterate over the queries and print the difference in cumulative sums
        for (List<Integer> problem : problems) {
            System.out.println(cumsum.get(problem.get(1) - 1) - cumsum.get(problem.get(0) - 1));
        }
    }
}

