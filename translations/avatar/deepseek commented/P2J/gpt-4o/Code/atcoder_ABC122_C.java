import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the length of the string and the number of queries
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read the string
        String s = scanner.nextLine();

        // Read the queries
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = scanner.nextInt();
            problems[i][1] = scanner.nextInt();
        }

        // Compute the cumulative sum of occurrences of 'AC'
        int[] cumsum = new int[n];
        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1];
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                cumsum[i]++;
            }
        }

        // Iterate over the queries and print the difference in cumulative sums
        for (int i = 0; i < q; i++) {
            int l = problems[i][0];
            int r = problems[i][1];
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
