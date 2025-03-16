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
        solve(N, x, y);
    }

    public static void solve(int N, int[] x, int[] y) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        List<List<Integer>> permutations = permute(indices);
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
        double result = distances.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        System.out.println(result);
    }

    public static List<List<Integer>> permute(List<Integer> nums) {
        List<List<Integer>> result = new ArrayList<>();
        permuteHelper(nums, 0, result);
        return result;
    }

    private static void permuteHelper(List<Integer> nums, int start, List<List<Integer>> result) {
        if (start == nums.size() - 1) {
            result.add(new ArrayList<>(nums));
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            Collections.swap(nums, i, start);
            permuteHelper(nums, start + 1, result);
            Collections.swap(nums, i, start);
        }
    }
}
