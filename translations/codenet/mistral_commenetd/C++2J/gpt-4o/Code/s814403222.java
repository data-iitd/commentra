import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a pair class with first integer and second string
    static class Pair implements Comparable<Pair> {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.first, other.first);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Initialize an array of pairs v with size 22
        Pair[] v = new Pair[22];
        // Initialize a list of lists for absences
        List<Integer>[] d = new ArrayList[33];

        // Initialize the lists in the array
        for (int i = 0; i < 33; i++) {
            d[i] = new ArrayList<>();
        }

        // Read the number of test cases n
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;

            // Initialize d array for each test case
            for (int i = 0; i < 33; i++) {
                d[i].clear();
            }

            // Process each test case
            for (int i = 0; i < n; i++) {
                // Initialize the first element of pair v[i] as 0
                v[i] = new Pair(0, "");
                // Read the name and number of students m for the current test case
                v[i].second = scanner.next();
                int m = scanner.nextInt();

                // For each student, read the number of absences a and update the scores accordingly
                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    // Calculate the effect of the current student's absences on the scores of other students
                    v[i].first += n - d[a].size();

                    // Update the scores of students who have the same number of absences as the current student
                    for (int k : d[a]) {
                        // Decrease the score of the student whose index is in d[a] by 1
                        v[k].first--;
                    }

                    // Add the index of the current student to the list d[a]
                    d[a].add(i);
                }
            }

            // Sort the pairs in the array v in ascending order based on their first elements
            Arrays.sort(v, 0, n);

            // Print the name and the highest score of the student with the highest score
            System.out.println(v[0].first + " " + v[0].second);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
