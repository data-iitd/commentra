import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();

        // Read the elements and count their occurrences using Counter
        Map<Integer, Integer> w = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            w.put(x, w.getOrDefault(x, 0) + 1);
        }

        // Initialize a counter for pairs that sum to zero
        int c = 0;

        // Iterate through each unique number in the counter
        for (int i : w.keySet()) {
            // Check if the number is zero
            if (i == 0) {
                // For zero, count pairs (w[i] choose 2) since both numbers are the same
                c += w.get(i) * (w.get(i) - 1);
            } else {
                // Check if the negative counterpart exists in the counter
                if (-i in w) {
                    // Count pairs formed by the number and its negative counterpart
                    c += w.get(i) * w.get(-i);
                }
            }
        }

        // Since each pair is counted twice, divide the total count by 2 before printing
        System.out.println(c / 2);
    }
}

