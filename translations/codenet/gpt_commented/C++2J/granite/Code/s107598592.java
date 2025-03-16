
import java.util.*;

public class s107598592{
    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize two lists to store the input values
        List<Integer> X = new ArrayList<>();
        List<Integer> Y = new ArrayList<>();

        // Read input values into list X and copy them to list Y
        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt();
            X.add(x);
            Y.add(x);
        }

        // Sort list Y to find the median
        Collections.sort(Y);

        // Find the median value (middle element for odd N, or lower middle for even N)
        int y = Y.get(N / 2);

        // Output the appropriate median value for each element in X
        for (int i = 0; i < N; i++) {
            // If the current element in X is less than the median
            if (X.get(i) < Y.get(N / 2)) {
                System.out.println(Y.get(N / 2)); // Output the upper median
            } else {
                System.out.println(Y.get(N / 2 - 1)); // Output the lower median
            }
        }
    }
}
