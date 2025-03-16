import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of characters in the string and the number of queries
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        
        // Read the input string
        String s = scanner.next();
        
        // Read the queries, each containing two integers l and r
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = scanner.nextInt();
            problems[i][1] = scanner.nextInt();
        }
        
        // Create a cumulative sum array to keep track of 'AC' occurrences
        int[] cumsum = new int[n + 1];
        
        // Calculate the cumulative sum array
        for (int i = 1; i <= n; i++) {
            cumsum[i] = cumsum[i - 1];
            if (s.charAt(i - 1) == 'A' && i < n && s.charAt(i) == 'C') {
                cumsum[i]++;
            }
        }
        
        // Process each query to find the number of 'AC' occurrences in the specified range
        for (int[] query : problems) {
            int l = query[0];
            int r = query[1];
            // Output the difference in cumulative sums to get the count in the range [l, r]
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }
        
        scanner.close();
    }
}
