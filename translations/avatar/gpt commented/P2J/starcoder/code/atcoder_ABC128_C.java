import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Reading the values of n and m from input
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Reading m lists of integers, each containing values after the first element
        int[][] li = new int[m][];
        for (int i = 0; i < m; i++) {
            li[i] = new int[sc.nextInt() - 1];
            for (int j = 0; j < li[i].length; j++) {
                li[i][j] = sc.nextInt();
            }
        }
        
        // Reading a tuple p from input
        int[] p = new int[sc.nextInt()];
        for (int i = 0; i < p.length; i++) {
            p[i] = sc.nextInt();
        }
        
        // Creating a set q that contains all unique elements from the lists in li
        Set<Integer> q = new HashSet<>();
        for (int[] l : li) {
            for (int e : l) {
                q.add(e);
            }
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
            for (Set<Integer> s : powerSet(q, i)) {
                // Checking each list in li against the corresponding value in p
                for (int j = 0; j < li.length; j++) {
                    if (s.size() % 2!= p[j]) {
                        break;
                    }
                    for (int e : li[j]) {
                        if (!s.contains(e)) {
                            break;
                        }
                    }
                } else {
                    // If all checks passed, increment the answer by 2 raised to the power of the size of v
                    ans += Math.pow(2, v.size());
                }
            }
        }
        
        // Printing the final answer
        System.out.println(ans);
    }
    
    // Returns all possible combinations of size k from the set s
    public static Set<Set<Integer>> powerSet(Set<Integer> s, int k) {
        Set<Set<Integer>> ans = new HashSet<>();
        if (k == 0) {
            ans.add(new HashSet<>());
            return ans;
        }
        for (Set<Integer> subset : powerSet(s, k - 1)) {
            for (int e : s) {
                Set<Integer> newSubset = new HashSet<>(subset);
                newSubset.add(e);
                ans.add(newSubset);
            }
        }
        return ans;
    }
}

