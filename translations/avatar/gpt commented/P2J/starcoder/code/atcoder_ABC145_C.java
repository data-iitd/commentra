import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of points
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        
        // Initialize lists to store x and y coordinates
        int[] x = new int[N];
        int[] y = new int[N];
        
        // Read the x and y coordinates for each point
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        
        // Call the solve function with the number of points and their coordinates
        solve(N, x, y);
    }
    
    public static void solve(int N, int[] x, int[] y) {
        // Create a list of indices from 0 to N-1
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }
        
        // Generate all possible permutations of the indices
        List<List<Integer>> permutations = new ArrayList<>();
        generatePermutations(permutations, indices);
        
        // Initialize a list to store the total distances for each permutation
        List<Double> distances = new ArrayList<>();
        
        // Iterate through each permutation of indices
        for (List<Integer> permutation : permutations) {
            double totalDistance = 0;
            
            // Calculate the total distance for the current permutation
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);  // Get the current and next index
                // Calculate the Euclidean distance between the two points
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;  // Accumulate the total distance
            }
            
            // Append the total distance for the current permutation to the list
            distances.add(totalDistance);
        }
        
        // Calculate the average distance across all permutations
        double result = 0;
        for (double distance : distances) {
            result += distance;
        }
        result /= distances.size();
        
        // Print the average distance
        System.out.println(result);
    }
    
    public static void generatePermutations(List<List<Integer>> permutations, List<Integer> indices) {
        if (indices.size() == 1) {
            permutations.add(indices);
            return;
        }
        
        for (int i = 0; i < indices.size(); i++) {
            List<Integer> newIndices = new ArrayList<>();
            newIndices.addAll(indices);
            newIndices.remove(i);
            generatePermutations(permutations, newIndices);
        }
    }
}

