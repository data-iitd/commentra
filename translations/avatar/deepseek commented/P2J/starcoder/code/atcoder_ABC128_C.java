import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of switches (n) and the number of bulbs (m)
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Read the connections of switches for each bulb and store them in a list (li)
        // Each element in li is a list of switches connected to a bulb, excluding the bulb itself
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> l = new ArrayList<>();
            int k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                l.add(sc.nextInt());
            }
            li.add(l);
        }
        
        // Read the pattern of on/off states for each bulb and store it in a tuple (p)
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = sc.nextInt();
        }
        
        // Create a set (q) containing all the switches from all the bulbs
        Set<Integer> q = new HashSet<>();
        for (List<Integer> l : li) {
            q.addAll(l);
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
            for (Set<Integer> s : powerSet(q, i)) {
                // Check if each combination satisfies the given pattern p
                for (int j = 0; j < m; j++) {
                    if (p[j]!= (s.containsAll(li.get(j))? 1 : 0)) {
                        break;
                    }
                } else {
                    // If a combination satisfies the pattern, increment the answer by 2^len(v)
                    ans += 1 << v.size();
                }
            }
        }
        
        // Print the total number of valid configurations
        System.out.println(ans);
    }
    
    // Returns all possible combinations of size i from a set
    public static <T> Set<Set<T>> powerSet(Set<T> s, int i) {
        Set<Set<T>> ans = new HashSet<>();
        if (i == 0) {
            ans.add(new HashSet<>());
            return ans;
        }
        for (Set<T> x : powerSet(s, i - 1)) {
            ans.add(x);
            ans.add(new HashSet<>(x));
            x.add(s.iterator().next());
        }
        return ans;
    }
}

