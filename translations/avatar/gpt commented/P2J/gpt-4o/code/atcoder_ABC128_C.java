import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Reading the values of n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Reading m lists of integers, each containing values after the first element
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int size = scanner.nextInt(); // Read the size of the list
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < size; j++) {
                list.add(scanner.nextInt());
            }
            li.add(list);
        }
        
        // Reading a tuple p from input
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }
        
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
        long ans = 0;
        
        // Iterating over all possible sizes of combinations from the set q
        List<Integer> qList = new ArrayList<>(q);
        int qSize = qList.size();
        for (int i = 0; i <= qSize; i++) {
            // Generating combinations of size i from the set q
            for (List<Integer> combination : combinations(qList, i)) {
                Set<Integer> s = new HashSet<>(combination);
                boolean valid = true;
                
                // Checking each list in li against the corresponding value in p
                for (int j = 0; j < m; j++) {
                    List<Integer> u = li.get(j);
                    int w = p[j];
                    // If the count of common elements is odd and does not match w, break
                    int count = 0;
                    for (int num : u) {
                        if (s.contains(num)) {
                            count++;
                        }
                    }
                    if (count % 2 != w) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    // If all checks passed, increment the answer by 2 raised to the power of the size of v
                    ans += (1L << v.size()); // 2^len(v) using bitwise shift
                }
            }
        }
        
        // Printing the final answer
        System.out.println(ans);
        
        // Closing the scanner
        scanner.close();
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
        boolean[] used = new boolean[n];
        generateCombinations(list, used, 0, size, result);
        return result;
    }
    
    // Helper method to generate combinations recursively
    private static void generateCombinations(List<Integer> list, boolean[] used, int start, int size, List<List<Integer>> result) {
        if (size == 0) {
            List<Integer> combination = new ArrayList<>();
            for (int i = 0; i < used.length; i++) {
                if (used[i]) {
                    combination.add(list.get(i));
                }
            }
            result.add(combination);
            return;
        }
        for (int i = start; i <= list.size() - size; i++) {
            used[i] = true;
            generateCombinations(list, used, i + 1, size - 1, result);
            used[i] = false;
        }
    }
}
// <END-OF-CODE>
