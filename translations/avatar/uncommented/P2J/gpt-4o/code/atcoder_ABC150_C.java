import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<List<Integer>> orig = new ArrayList<>();
        
        // Generate all permutations of numbers from 1 to n
        generatePermutations(new ArrayList<>(), new boolean[n + 1], orig, n);
        
        // Read the two permutations
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        
        List<Integer> q = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }
        
        // Find the indices of p and q in orig
        int pn = orig.indexOf(p);
        int qn = orig.indexOf(q);
        
        // Print the absolute difference
        System.out.println(Math.abs(pn - qn));
    }
    
    private static void generatePermutations(List<Integer> current, boolean[] used, List<List<Integer>> result, int n) {
        if (current.size() == n) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                current.add(i);
                generatePermutations(current, used, result, n);
                current.remove(current.size() - 1);
                used[i] = false;
            }
        }
    }
}

// <END-OF-CODE>
