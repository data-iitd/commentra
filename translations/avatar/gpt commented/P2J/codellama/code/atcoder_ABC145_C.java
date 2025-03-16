import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Solution {
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
        // Create a list of indices from 0 to N-1
        List<Integer> indices = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            indices.add(i);
        }

        // Generate all possible permutations of the indices
        List<List<Integer>> permutations = getPermutations(indices);

        // Initialize a list to store the total distances for each permutation
        List<Double> distances = new ArrayList<Double>();

        // Iterate through each permutation of indices
        for (List<Integer> permutation : permutations) {
            double totalDistance = 0;

            // Calculate the total distance for the current permutation
            for (int i = 0; i < N - 1; i++) {
                int f = permutation.get(i);
                int t = permutation.get(i + 1);
                // Calculate the Euclidean distance between the two points
                double distance = Math.sqrt(Math.pow(x[t] - x[f], 2) + Math.pow(y[t] - y[f], 2));
                totalDistance += distance;
            }

            // Append the total distance for the current permutation to the list
            distances.add(totalDistance);
        }

        // Calculate the average distance across all permutations
        double result = distances.stream().mapToDouble(Double::doubleValue).sum() / distances.size();

        // Print the average distance
        System.out.println(result);
    }

    public static List<List<Integer>> getPermutations(List<Integer> list) {
        List<List<Integer>> permutations = new ArrayList<List<Integer>>();
        if (list.size() == 1) {
            permutations.add(list);
        } else {
            for (int i = 0; i < list.size(); i++) {
                Integer element = list.get(i);
                List<Integer> remaining = new ArrayList<Integer>(list);
                remaining.remove(i);
                for (List<Integer> permutation : getPermutations(remaining)) {
                    permutation.add(0, element);
                    permutations.add(permutation);
                }
            }
        }
        return permutations;
    }
}

