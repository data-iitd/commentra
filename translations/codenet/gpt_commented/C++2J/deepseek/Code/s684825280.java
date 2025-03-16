import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a constant size for the count array
    static final int SIZE = (int) (1e5 * 2) + 13;

    // Declare a list to hold the counts of each number
    static List<Integer> a = new ArrayList<>();
    // Declare a count array initialized to zero with a size of SIZE
    static List<Integer> cnt = new ArrayList<>(Collections.nCopies(SIZE, 0));

    public static void main(String[] args) {
        // Read the number of elements (n) and the number of largest counts to keep (k)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Read n integers and count their occurrences
        for (int i = 0; i < n; ++i) {
            int x = scanner.nextInt();
            // Increment the count for the number x
            cnt.set(x, cnt.get(x) + 1);
        }

        // Transfer the counts of numbers that appeared at least once to list a
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt.get(i) > 0)
                a.add(cnt.get(i)); // Add the count to list a
        }

        // Initialize the answer variable to accumulate the result
        int ans = 0;
        // Sort the counts in ascending order
        Collections.sort(a);

        // Calculate the number of counts to exclude (m) based on k
        int m = a.size() - k;
        // Sum the counts of the smallest m elements
        for (int i = 0; i < m; ++i) {
            ans += a.get(i); // Add the count to the answer
        }

        // Output the final answer
        System.out.println(ans);
    }
}
