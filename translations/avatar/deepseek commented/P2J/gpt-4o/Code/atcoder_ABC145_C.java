import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    
    public static void solve(int N, int[] x, int[] y) {
        // Generate a list of indices from 0 to N-1
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        
        // Initialize a list to store the total distances for each permutation
        List<Double> distances = new ArrayList<>();
        
        // Generate all permutations of the indices
        permute(indices, 0, N, distances, x, y);
        
        // Calculate the average distance by averaging all stored distances
        double result = distances.stream().mapToDouble(Double::doubleValue).sum() / distances.size();
        
        // Print the result
        System.out.println(result);
    }
    
    private static void permute(List<Integer> indices, int start, int end, List<Double> distances, int[] x, int[] y) {
        if (start == end - 1) {
            // Calculate the total distance for the current permutation
            double totalDistance = 0;
            for (int i = 0; i < end - 1; i++) {
                int f = indices.get(i);
                int t = indices.get(i + 1);
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }
            distances.add(totalDistance);
        } else {
            for (int i = start; i < end; i++) {
                swap(indices, start, i);
                permute(indices, start + 1, end, distances, x, y);
                swap(indices, start, i); // backtrack
            }
        }
    }
    
    private static void swap(List<Integer> indices, int i, int j) {
        int temp = indices.get(i);
        indices.set(i, indices.get(j));
        indices.set(j, temp);
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
        
        scanner.close();
    }
}

// <END-OF-CODE>
