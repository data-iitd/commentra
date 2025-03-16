import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the values of n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();  // Consume newline
        
        // Reading m lists of integers, each containing values after the first element
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String[] parts = scanner.nextLine().split(" ");
            List<Integer> list = new ArrayList<>();
            for (int j = 1; j < parts.length; j++) {
                list.add(Integer.parseInt(parts[j]));
            }
            li.add(list);
        }
        
        // Reading a tuple p from input
        int[] p = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        // Creating a set q that contains all unique elements from the lists in li
        Set<Integer> q = new HashSet<>();
        for (List<Integer> list : li) {
            q.addAll(list);
        }
        
        // Creating a set r that contains all integers from 1 to n
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }
        
        // Finding the set of values v that are in r but not in q
        Set<Integer> v = new HashSet<>(r);
        v.removeAll(q);
        
        // Initializing the answer variable to count valid combinations
        int ans = 0;
        
        // Iterating over all possible sizes of combinations from the set q
        for (int i = 0; i <= q.size(); i++) {
            // Generating combinations of size i from the set q
            List<Set<Integer>> combinations = new ArrayList<>();
            generateCombinations(q, i, new HashSet<>(), combinations);
            
            // Checking each list in li against the corresponding value in p
            for (Set<Integer> s : combinations) {
                for (int j = 0; j < m; j++) {
                    List<Integer> u = li.get(j);
                    int w = p[j];
                    s = new HashSet<>(s);  // Converting the combination to a set for intersection
                    // If the count of common elements is odd and does not match w, break
                    if (Collections.frequency(u, 1) % 2 != w) {
                        break;
                    }
                }
                else {
                    // If all checks passed, increment the answer by 2 raised to the power of the size of v
                    ans += Math.pow(2, v.size());
                }
            }
        }
        
        // Printing the final answer
        System.out.println(ans);
    }
    
    // Helper method to generate combinations of a given size from a set
    private static void generateCombinations(Set<Integer> set, int size, Set<Integer> current, List<Set<Integer>> combinations) {
        if (current.size() == size) {
            combinations.add(new HashSet<>(current));
            return;
        }
        for (Integer element : set) {
            if (current.contains(element)) continue;
            current.add(element);
            generateCombinations(set, size, current, combinations);
            current.remove(element);
        }
    }
}
