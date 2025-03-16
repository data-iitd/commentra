import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to find the solution
    public static void solve(int N, int[] x, int[] y) {
        // Initialize a list to store distances
        List<Double> distances = new ArrayList<>();

        // Generate all possible permutations of indices from 0 to N-1
        int[] indices = new int[N];
        for (int i = 0; i < N; i++) {
            indices[i] = i;
        }

        // Generate permutations and calculate distances
        permute(indices, 0, N, x, y, distances);

        // Calculate the average distance from all permutations
        double result = distances.stream().mapToDouble(Double::doubleValue).sum() / distances.size();

        // Print the result
        System.out.println(result);
    }

    // Helper method to generate permutations
    private static void permute(int[] arr, int l, int r, int[] x, int[] y, List<Double> distances) {
        if (l == r) {
            double totalDistance = 0;
            for (int i = 0; i < arr.length - 1; i++) {
                int f = arr[i];
                int t = arr[i + 1];
                // Calculate the Euclidean distance
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }
            distances.add(totalDistance);
        } else {
            for (int i = l; i < r; i++) {
                swap(arr, l, i);
                permute(arr, l + 1, r, x, y, distances);
                swap(arr, l, i); // backtrack
            }
        }
    }

    // Helper method to swap elements in an array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Main function to read input and call the solve function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points
        int N = scanner.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        
        // Read the coordinates
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }

        // Call the solve function with the given input
        solve(N, x, y);
        
        scanner.close();
    }
}

// <END-OF-CODE>
