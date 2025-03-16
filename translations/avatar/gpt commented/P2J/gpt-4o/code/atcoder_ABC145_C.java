import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    
    public static void solve(int N, int[] x, int[] y) {
        // Create a list of indices from 0 to N-1
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        
        // Generate all possible permutations of the indices
        List<List<Integer>> permutations = new ArrayList<>();
        permute(indices, 0, permutations);
        
        // Initialize a list to store the total distances for each permutation
        List<Double> distances = new ArrayList<>();
        
        // Iterate through each permutation of indices
        for (List<Integer> permutation : permutations) {
            double totalDistance = 0;
            
            // Calculate the total distance for the current permutation
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);  // Get the current index
                int t = permutation.get(i + 1);  // Get the next index
                // Calculate the Euclidean distance between the two points
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;  // Accumulate the total distance
            }
            
            // Append the total distance for the current permutation to the list
            distances.add(totalDistance);
        }
        
        // Calculate the average distance across all permutations
        double result = distances.stream().mapToDouble(Double::doubleValue).sum() / distances.size();
        
        // Print the average distance
        System.out.println(result);
    }
    
    private static void permute(List<Integer> indices, int start, List<List<Integer>> result) {
        if (start >= indices.size()) {
            result.add(new ArrayList<>(indices));
            return;
        }
        for (int i = start; i < indices.size(); i++) {
            swap(indices, start, i);
            permute(indices, start + 1, result);
            swap(indices, start, i); // backtrack
        }
    }
    
    private static void swap(List<Integer> list, int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points
        int N = scanner.nextInt();
        
        // Initialize arrays to store x and y coordinates
        int[] x = new int[N];
        int[] y = new int[N];
        
        // Read the x and y coordinates for each point
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        
        // Call the solve function with the number of points and their coordinates
        solve(N, x, y);
        
        scanner.close();
    }
}

// <END-OF-CODE>
