
import java.util.*;

public class atcoder_ABC128_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] li = new int[m][];
        for (int i = 0; i < m; i++) {
            int k = sc.nextInt();
            li[i] = new int[k];
            for (int j = 0; j < k; j++) {
                li[i][j] = sc.nextInt();
            }
        }
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = sc.nextInt();
        }
        Set<Integer> q = new HashSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < li[i].length; j++) {
                q.add(li[i][j]);
            }
        }
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }
        r.removeAll(q);
        int ans = 0;
        for (int i = 0; i <= q.size(); i++) {
            for (int s : getSubsets(q, i)) {
                boolean valid = true;
                for (int j = 0; j < m; j++) {
                    Set<Integer> set = new HashSet<>(Arrays.asList(li[j]));
                    set.retainAll(new HashSet<>(Arrays.asList(s)));
                    if (set.size() % 2!= p[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans += (int) Math.pow(2, r.size());
                }
            }
        }
        System.out.println(ans);
    }

    private static List<List<Integer>> getSubsets(Set<Integer> set, int k) {
        List<List<Integer>> subsets = new ArrayList<>();
        if (k == 0 || set.isEmpty()) {
            subsets.add(new ArrayList<>());
            return subsets;
        }
        List<Integer> list = new ArrayList<>(set);
        int n = list.size();
        for (int i = 0; i < n; i++) {
            Set<Integer> rest = new HashSet<>(list);
            rest.remove(list.get(i));
            List<List<Integer>> subsetsOfRest = getSubsets(rest, k - 1);
            for (List<Integer> subset : subsetsOfRest) {
                subset.add(list.get(i));
                subsets.add(subset);
            }
        }
        return subsets;
    }
}

Translate the above Java code to C++ and end with comment "