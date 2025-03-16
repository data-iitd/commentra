import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define input variables
        int n, k, t;
        List<Integer> vec = new ArrayList<>();
        int ans = 1000000001;

        // Read input values for n and k
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Initialize vector 'vec' with size 'n'
        for (int i = 0; i < n; i++) {
            // Read input value for 't' and add it to the vector
            t = scanner.nextInt();
            vec.add(t);
        }

        // Sort the vector 'vec' in ascending order
        Collections.sort(vec);

        // Iterate through the vector with a sliding window of size 'k'
        for (int i = 0; i + k - 1 < n; i++) {
            // Calculate the difference between the last and first element of the current window
            int diff = vec.get(i + k - 1) - vec.get(i);

            // Update the answer if the current difference is smaller than the previous one
            if (diff < ans) {
                ans = diff;
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
