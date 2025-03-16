public class Main {
    public static void main(String[] args) {
        // Read the number of switches (n) and the number of bulbs (m)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Read the connections of switches for each bulb and store them in a list (li)
        // Each element in li is a list of switches connected to a bulb, excluding the bulb itself
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> u = new ArrayList<>();
            for (int j = 0; j < n - 1; j++) {
                u.add(sc.nextInt());
            }
            li.add(u);
        }
        
        // Read the pattern of on/off states for each bulb and store it in a tuple (p)
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            p.add(sc.nextInt());
        }
        
        // Create a set (q) containing all the switches from all the bulbs
        Set<Integer> q = new HashSet<>();
        for (List<Integer> u : li) {
            q.addAll(u);
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
        long ans = 0;
        
        // Iterate over all possible combinations of switches from q
        for (int i = 0; i <= q.size(); i++) {
            for (List<Integer> s : combinations(q, i)) {
                // Check if each combination satisfies the given pattern p
                for (int j = 0; j < m; j++) {
                    Set<Integer> u = new HashSet<>(li.get(j));
                    if (u.size() % 2 != p.get(j)) {
                        break;
                    }
                }
                // If a combination satisfies the pattern, increment the answer by 2^len(v)
                ans += (long) Math.pow(2, v.size());
            }
        }
        
        // Print the total number of valid configurations
        System.out.println(ans);
    }
    
    // Generate all possible combinations of a set with k elements
    public static List<List<Integer>> combinations(Set<Integer> s, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        if (k == 0) {
            ans.add(new ArrayList<>());
            return ans;
        }
        for (int i : s) {
            for (List<Integer> u : combinations(s, k - 1)) {
                u.add(i);
                ans.add(u);
            }
        }
        return ans;
    }
}
