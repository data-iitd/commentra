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

        double totalDistance = 0;
        List<Double> distances = new ArrayList<>();

        List<List<Integer>> permutations = new ArrayList<>(new Permutations<>(indices));

        for (List<Integer> permutation : permutations) {
            double currentDistance = 0;
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);
                currentDistance += Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
            }
            distances.add(currentDistance);
        }

        for (double distance : distances) {
            totalDistance += distance;
        }

        return totalDistance / distances.size();
    }
}

class Permutations<T> extends ArrayList<List<T>> {
    public Permutations(List<T> list) {
        permute(list, 0, list.size() - 1);
    }

    private void permute(List<T> list, int l, int r) {
        if (l == r) {
            this.add(new ArrayList<>(list));
        } else {
            for (int i = l; i <= r; i++) {
                Collections.swap(list, l, i);
                permute(list, l + 1, r);
                Collections.swap(list, l, i); // backtrack
            }
        }
    }
}
