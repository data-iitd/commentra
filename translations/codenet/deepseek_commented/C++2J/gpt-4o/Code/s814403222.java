import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Pair {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break; // Read n until it is zero

            int[][] d = new int[33][];
            for (int i = 0; i < 33; i++) {
                d[i] = new int[0]; // Initialize each vector in d
            }

            Pair[] v = new Pair[n]; // Array to store n pairs
            for (int i = 0; i < n; i++) {
                v[i] = new Pair(0, scanner.next()); // Initialize the first element of v to 0 and read the string
                int m = scanner.nextInt(); // Read m for each element
                List<Integer> indices = new ArrayList<>(); // List to store indices for current element

                for (int j = 0; j < m; j++) { // For each m, read an integer and update v and d
                    int a = scanner.nextInt();
                    v[i].first += n - d[a].length; // Update the first element of v
                    for (int k = 0; k < d[a].length; k++) { // Update the first elements of other v elements
                        v[d[a][k]].first--;
                    }
                    indices.add(i); // Store the index of the current element in indices
                }
                d[a] = indices.stream().mapToInt(Integer::intValue).toArray(); // Store indices in d
            }

            // Sort the array v based on the first element of Pair
            Arrays.sort(v, Comparator.comparingInt(p -> p.first));
            System.out.println(v[0].first + " " + v[0].second); // Output the first element of v
        }
        scanner.close();
    }
}
