
import java.util.*;

public class atcoder_ABC145_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        solve(N, x, y);
    }

    public static void solve(int N, int[] x, int[] y) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        List<List<Integer>> permutations = getPermutations(indices);
        List<Double> distances = new ArrayList<>();
        for (List<Integer> permutation : permutations) {
            double totalDistance = 0;
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }
            distances.add(totalDistance);
        }
        double result = distances.stream().mapToDouble(d -> d).average().orElse(0);
        System.out.println(result);
    }

    public static List<List<Integer>> getPermutations(List<Integer> list) {
        if (list.size() <= 1) {
            return Collections.singletonList(list);
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            Integer element = list.get(i);
            List<Integer> remaining = new ArrayList<>(list);
            remaining.remove(i);
            for (List<Integer> permutation : getPermutations(remaining)) {
                List<Integer> newPermutation = new ArrayList<>();
                newPermutation.add(element);
                newPermutation.addAll(permutation);
                result.add(newPermutation);
            }
        }
        return result;
    }
}

Translate the above Java code to C++ and end with comment "