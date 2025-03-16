import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of switches (n) and the number of bulbs (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the connections of switches for each bulb and store them in a list (li)
        // Each element in li is a list of switches connected to a bulb, excluding the bulb itself
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt();
            List<Integer> switches = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                switches.add(scanner.nextInt());
            }
            li.add(switches);
        }
        
        // Read the pattern of on/off states for each bulb and store it in a list (p)
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            p.add(scanner.nextInt());
        }
        
        // Create a set (q) containing all the switches from all the bulbs
        Set<Integer> q = new HashSet<>();
        for (List<Integer> switches : li) {
            q.addAll(switches);
        }
        
        // Create a set (r) containing all the switches from 1 to n
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }
        
        // Calculate the set (v) which contains the switches that are not connected to any bulb
        Set<Integer> v = new HashSet<>(r);
        v.removeAll(q);
        
        // Initialize the answer variable to count the number of valid configurations
        int ans = 0;
        
        // Iterate over all possible combinations of switches from q
        for (int i = 0; i <= q.size(); i++) {
            for (Set<Integer> s : combinations(q, i)) {
                // Check if each combination satisfies the given pattern p
                boolean valid = true;
                for (int j = 0; j < m; j++) {
                    List<Integer> u = li.get(j);
                    int w = p.get(j);
                    if (countOnSwitches(s, u) % 2 != w) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    // If a combination satisfies the pattern, increment the answer by 2^len(v)
                    ans += Math.pow(2, v.size());
                }
            }
        }
        
        // Print the total number of valid configurations
        System.out.println(ans);
    }
    
    // Helper method to generate combinations
    public static <T> List<Set<T>> combinations(Set<T> elements, int k) {
        List<Set<T>> result = new ArrayList<>();
        combinationsHelper(new ArrayList<>(elements), k, new HashSet<>(), result);
        return result;
    }
    
    private static <T> void combinationsHelper(List<T> elements, int k, Set<T> current, List<Set<T>> result) {
        if (current.size() == k) {
            result.add(new HashSet<>(current));
            return;
        }
        if (elements.isEmpty()) {
            return;
        }
        T head = elements.remove(0);
        current.add(head);
        combinationsHelper(elements, k, current, result);
        current.remove(head);
        combinationsHelper(elements, k, current, result);
        elements.add(0, head);
    }
    
    // Helper method to count the number of elements in the intersection of two sets
    public static int countOnSwitches(Set<Integer> set1, List<Integer> list2) {
        int count = 0;
        for (Integer i : list2) {
            if (set1.contains(i)) {
                count++;
            }
        }
        return count;
    }
}
