import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input: number of test cases, number of lists, and the lists themselves
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt();
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                row.add(scanner.nextInt());
            }
            li.add(row);
        }

        // Read input: pattern
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }

        // Create a set of all elements in the lists
        Set<Integer> q = new HashSet<>();
        for (List<Integer> row : li) {
            q.addAll(row);
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
        int ans = 0;

        // Iterate through all possible subsets of q, from empty to the full set
        for (int i = 0; i <= q.size(); i++) {
            // Iterate through all combinations of i elements from q
            for (Set<Integer> s : combinations(q, i)) {
                // Iterate through each list and pattern
                for (int j = 0; j < m; j++) {
                    // Check if the current combination of lists and pattern match the current subset of q
                    int count = 0;
                    for (Integer num : s) {
                        if (li.get(j).contains(num)) {
                            count++;
                        }
                    }
                    if (count % 2 != p[j]) {
                        // If not, break out of the inner loop and move on to the next combination
                        break;
                    }
                }
                // If all combinations of lists and pattern match the current subset of q, increment the answer
                else {
                    ans += Math.pow(2, v.size());
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }

    // Helper method to generate all combinations of a given size from a set
    public static <T> List<Set<T>> combinations(Set<T> set, int size) {
        List<Set<T>> result = new ArrayList<>();
        if (size == 0) {
            result.add(new HashSet<>());
            return result;
        }
        List<T> elements = new ArrayList<>(set);
        int n = elements.size();
        for (int i = 0; i < (1 << n); i++) {
            if (Integer.bitCount(i) == size) {
                Set<T> combination = new HashSet<>();
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        combination.add(elements.get(j));
                    }
                }
                result.add(combination);
            }
        }
        return result;
    }
}
