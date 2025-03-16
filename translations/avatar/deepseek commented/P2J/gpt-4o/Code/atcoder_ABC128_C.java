import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of switches (n) and the number of bulbs (m)
        String[] nm = scanner.nextLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        
        // Read the connections of switches for each bulb and store them in a list (li)
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String[] connections = scanner.nextLine().split(" ");
            List<Integer> switches = new ArrayList<>();
            for (int j = 1; j < connections.length; j++) {
                switches.add(Integer.parseInt(connections[j]));
            }
            li.add(switches);
        }
        
        // Read the pattern of on/off states for each bulb and store it in an array (p)
        String[] patternInput = scanner.nextLine().split(" ");
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = Integer.parseInt(patternInput[i]);
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
        long ans = 0;
        
        // Iterate over all possible combinations of switches from q
        List<Integer> qList = new ArrayList<>(q);
        int qSize = qList.size();
        for (int i = 0; i <= qSize; i++) {
            for (List<Integer> combination : combinations(qList, i)) {
                Set<Integer> s = new HashSet<>(combination);
                boolean valid = true;
                
                // Check if each combination satisfies the given pattern p
                for (int j = 0; j < m; j++) {
                    List<Integer> u = li.get(j);
                    int w = p[j];
                    int count = 0;
                    for (int switchNum : u) {
                        if (s.contains(switchNum)) {
                            count++;
                        }
                    }
                    if (count % 2 != w) {
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
    
    // Method to generate combinations of a given size from a list
    private static List<List<Integer>> combinations(List<Integer> list, int size) {
        List<List<Integer>> result = new ArrayList<>();
        if (size == 0) {
            result.add(new ArrayList<>());
            return result;
        }
        if (list.size() < size) {
            return result;
        }
        int n = list.size();
        int[] indices = new int[size];
        for (int i = 0; i < size; i++) {
            indices[i] = i;
        }
        while (true) {
            List<Integer> combination = new ArrayList<>();
            for (int index : indices) {
                combination.add(list.get(index));
            }
            result.add(combination);
            int i;
            for (i = size - 1; i >= 0 && indices[i] == n - size + i; i--);
            if (i < 0) {
                break;
            }
            indices[i]++;
            for (int j = i + 1; j < size; j++) {
                indices[j] = indices[j - 1] + 1;
            }
        }
        return result;
    }
}
// <END-OF-CODE>
