import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<List<Integer>> li = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt(); // Read the size of the list
            List<Integer> tempList = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                tempList.add(scanner.nextInt());
            }
            li.add(tempList);
        }
        
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }
        
        Set<Integer> q = new HashSet<>();
        for (List<Integer> list : li) {
            q.addAll(list);
        }
        
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }
        
        Set<Integer> v = new HashSet<>(r);
        v.removeAll(q);
        
        long ans = 0;
        int qSize = q.size();
        List<Integer> qList = new ArrayList<>(q);
        
        for (int i = 0; i <= qSize; i++) {
            for (List<Integer> combination : combinations(qList, i)) {
                Set<Integer> s = new HashSet<>(combination);
                boolean valid = true;
                
                for (int j = 0; j < li.size(); j++) {
                    List<Integer> u = li.get(j);
                    int w = p[j];
                    if (s.stream().filter(u::contains).count() % 2 != w) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    ans += (1L << v.size()); // 2^v.size()
                }
            }
        }
        
        System.out.println(ans);
    }
    
    private static List<List<Integer>> combinations(List<Integer> list, int k) {
        List<List<Integer>> result = new ArrayList<>();
        if (k == 0) {
            result.add(new ArrayList<>());
            return result;
        }
        if (list.isEmpty()) {
            return result;
        }
        
        Integer first = list.remove(0);
        List<List<Integer>> withoutFirst = combinations(list, k);
        List<List<Integer>> withFirst = combinations(list, k - 1);
        
        for (List<Integer> combination : withFirst) {
            combination.add(first);
            result.add(combination);
        }
        
        result.addAll(withoutFirst);
        list.add(0, first); // Restore the original list
        return result;
    }
}
