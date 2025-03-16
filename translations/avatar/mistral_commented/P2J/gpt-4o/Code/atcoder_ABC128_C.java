import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input: number of test cases, number of lists, and the lists themselves
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<Set<Integer>> li = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int size = scanner.nextInt();
            Set<Integer> set = new HashSet<>();
            for (int j = 0; j < size; j++) {
                set.add(scanner.nextInt());
            }
            li.add(set);
        }

        // Read input: pattern
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }

        // Create a set of all elements in the lists
        Set<Integer> q = new HashSet<>();
        for (Set<Integer> set : li) {
            q.addAll(set);
        }

        // Create a set of numbers from 1 to n (excluding n)
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }

        // Find the set of numbers in r that are not in q
        Set<Integer> v = new HashSet<>(r);
        v.removeAll(q);

        // Initialize answer to 0
        long ans = 0;

        // Iterate through all possible subsets of q
        List<Integer> qList = new ArrayList<>(q);
        int qSize = qList.size();
        for (int i = 0; i < (1 << qSize); i++) {
            Set<Integer> s = new HashSet<>();
            for (int j = 0; j < qSize; j++) {
                if ((i & (1 << j)) > 0) {
                    s.add(qList.get(j));
                }
            }

            // Check if the current combination of lists and pattern match the current subset of q
            boolean valid = true;
            for (int u = 0; u < m; u++) {
                Set<Integer> currentList = li.get(u);
                int count = 0;
                for (Integer element : s) {
                    if (currentList.contains(element)) {
                        count++;
                    }
                }
                if (count % 2 != p[u]) {
                    valid = false;
                    break;
                }
            }

            // If all combinations of lists and pattern match the current subset of q, increment the answer
            if (valid) {
                ans += (1L << v.size());
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
