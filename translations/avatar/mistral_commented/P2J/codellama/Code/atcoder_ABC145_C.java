// Import necessary libraries
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

// Function to find the solution
public static void solve(int N, int[] x, int[] y) {
    // Initialize an empty list to store distances
    List<Double> distances = new ArrayList<>();

    // Generate all possible permutations of indices from 0 to N-1
    int[] indices = new int[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    List<List<Integer>> permutations = getPermutations(indices);

    // For each permutation, calculate the total distance between adjacent points
    for (List<Integer> permutation : permutations) {
        double totalDistance = 0;
        for (int i = 0; i < N - 1; i++) {
            // Get the first and second indices of the current pair
            int f = permutation.get(i);
            int t = permutation.get(i + 1);
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
            // Add the distance to the total distance
            totalDistance += distance;
        }
        // Append the total distance to the distances list
        distances.add(totalDistance);
    }

    // Calculate the average distance from all permutations
    double result = distances.stream().mapToDouble(Double::doubleValue).sum() / distances.size();

    // Print the result
    System.out.println(result);
}

// Function to generate all possible permutations of a given array
public static List<List<Integer>> getPermutations(int[] array) {
    List<List<Integer>> permutations = new ArrayList<>();
    if (array.length == 1) {
        permutations.add(Arrays.asList(array[0]));
        return permutations;
    }
    for (int i = 0; i < array.length; i++) {
        int[] remaining = Arrays.copyOfRange(array, i + 1, array.length);
        List<List<Integer>> subPermutations = getPermutations(remaining);
        for (List<Integer> subPermutation : subPermutations) {
            subPermutation.add(0, array[i]);
            permutations.add(subPermutation);
        }
    }
    return permutations;
}

// Main function to read input and call the solve function
public static void main(String[] args) {
    // Function to read tokens from standard input
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

// End of code
