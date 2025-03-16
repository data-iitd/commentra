

import java.util.Scanner;

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
        // Generate a list of indices from 0 to N-1
        int[] indices = new int[N];
        for (int i = 0; i < N; i++) {
            indices[i] = i;
        }

        // Generate all permutations of the indices
        int[][] permutations = new int[N][N];
        for (int i = 0; i < N; i++) {
            permutations[i] = indices.clone();
            for (int j = 0; j < N - i - 1; j++) {
                int k = (int) (Math.random() * (N - j));
                int temp = permutations[i][j + k];
                permutations[i][j + k] = permutations[i][j];
                permutations[i][j] = temp;
            }
        }

        // Initialize a list to store the total distances for each permutation
        double[] distances = new double[N];

        // Iterate over each permutation
        for (int i = 0; i < N; i++) {
            // Initialize the total distance for the current permutation
            double totalDistance = 0;

            // Calculate the distance between consecutive points in the permutation
            for (int j = 0; j < N - 1; j++) {
                int f = permutations[i][j];
                int t = permutations[i][j + 1];
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }

            // Append the total distance of the current permutation to the distances list
            distances[i] = totalDistance;
        }

        // Calculate the average distance by averaging all stored distances
        double result = 0;
        for (int i = 0; i < N; i++) {
            result += distances[i];
        }
        result /= N;

        // Print the result
        System.out.println(result);
    }
}

Translate the above Java code to C++ and end with comment "