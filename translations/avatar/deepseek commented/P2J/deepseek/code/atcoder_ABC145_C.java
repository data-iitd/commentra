import java.util.*;

public class Main {
    public static void solve(int N, int[] x, int[] y) {
        // Generate a list of indices from 0 to N-1
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        
        // Generate all permutations of the indices
        List<List<Integer>> permutations = new ArrayList<>(new Permutations<>(indices).get());
        
        // Initialize a list to store the total distances for each permutation
        List<Double> distances = new ArrayList<>();
        
        // Iterate over each permutation
        for (List<Integer> permutation : permutations) {
            // Initialize the total distance for the current permutation
            double totalDistance = 0;
            
            // Calculate the distance between consecutive points in the permutation
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }
            
            // Append the total distance of the current permutation to the distances list
            distances.add(totalDistance);
        }
        
        // Calculate the average distance by averaging all stored distances
        double result = distances.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        
        // Print the result
        System.out.println(result);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points N
        int N = scanner.nextInt();
        
        // Initialize arrays for x and y coordinates
        int[] x = new int[N];
        int[] y = new int[N];
        
        // Read the x and y coordinates for each point
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        
        // Call the solve function with the input values
        solve(N, x, y);
    }
}

class Permutations<T> extends AbstractList<List<T>> {
    private final List<T> list;
    private final int size;

    public Permutations(List<T> list) {
        this.list = new ArrayList<>(list);
        this.size = factorial(list.size());
    }

    private int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    @Override
    public List<T> get(int index) {
        List<T> result = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            result.add(list.get((index / factorial(i)) % list.size()));
        }
        return result;
    }

    @Override
    public int size() {
        return size;
    }
}
