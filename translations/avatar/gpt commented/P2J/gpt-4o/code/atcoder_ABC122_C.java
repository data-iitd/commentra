import java.util.Scanner;

public class CountAC {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of characters in the string and the number of queries
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Read the input string
        String s = scanner.nextLine();

        // Create an array to store the cumulative sum of 'AC' occurrences
        int[] cumsum = new int[n];

        // Initialize the cumulative sum
        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1];
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                cumsum[i]++;
            }
        }

        // Process each query to find the number of 'AC' occurrences in the specified range
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            // Output the difference in cumulative sums to get the count in the range [l, r]
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
