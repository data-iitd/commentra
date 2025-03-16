// Import necessary libraries
import java.util.Scanner;

// Function to find the solution
public static void solve(int N, int[] x, int[] y) {
    // Initialize an empty list to store distances
    List<Double> distances = new ArrayList<>();

    // Generate all possible permutations of indices from 0 to N-1
    List<Integer> indices = new ArrayList<>();
    for (int i = 0; i < N; i++) {
        indices.add(i);
    }
    List<List<Integer>> permutations = new ArrayList<>();
    permutations.add(new ArrayList<>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < permutations.size(); j++) {
            List<Integer> current = new ArrayList<>(permutations.get(j));
            current.add(indices.get(i));
            permutations.add(current);
        }
    }

    // For each permutation, calculate the total distance between adjacent points
    for (List<Integer> permutation : permutations) {
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            // Get the first and second indices of the current pair
            int f = permutation.get(i);
            int t = permutation.get(i + 1);
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
            // Add the distance to the total distance
            total_distance += distance;
        }
        // Append the total distance to the distances list
        distances.add(total_distance);
    }

    // Calculate the average distance from all permutations
    double result = 0;
    for (double distance : distances) {
        result += distance;
    }
    result /= distances.size();

    // Print the result
    System.out.println(result);
}

// Main function to read input and call the solve function
public static void main(String[] args) {
    // Read the number of points and their coordinates from input
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] x = new int[N];
    int[] y = new int[N];
    for (int i = 0; i < N; i++) {
        x[i] = scanner.nextInt();
        y[i] = scanner.nextInt();
    }

    // Call the solve function with the given input
    solve(N, x, y);
}

