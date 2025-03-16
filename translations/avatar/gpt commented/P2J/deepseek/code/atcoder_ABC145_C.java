import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        
        double result = solve(N, x, y);
        System.out.println(result);
    }
    
    public static double solve(int N, int[] x, int[] y) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        
        List<List<Integer>> permutations = new ArrayList<>(new Permutations<>(indices).getList());
        double totalDistance = 0;
        
        for (List<Integer> permutation : permutations) {
            double currentDistance = 0;
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);
                currentDistance += Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
            }
            totalDistance += currentDistance;
        }
        
        return totalDistance / permutations.size();
    }
    
    static class Permutations<T> {
        private final List<T> list;
        private final List<List<T>> result;
        
        public Permutations(List<T> list) {
            this.list = list;
            this.result = new ArrayList<>();
            permute(new ArrayList<>(), new boolean[list.size()]);
        }
        
        private void permute(List<T> current, boolean[] used) {
            if (current.size() == list.size()) {
                result.add(new ArrayList<>(current));
                return;
            }
            
            for (int i = 0; i < list.size(); i++) {
                if (!used[i]) {
                    current.add(list.get(i));
                    used[i] = true;
                    permute(current, used);
                    current.remove(current.size() - 1);
                    used[i] = false;
                }
            }
        }
        
        public List<List<T>> getList() {
            return result;
        }
    }
}
