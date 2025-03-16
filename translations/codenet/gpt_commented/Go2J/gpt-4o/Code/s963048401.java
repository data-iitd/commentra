import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Set the modulus value to 1000000007
        final int mod = 1000000007;

        // Create a scanner to read input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();

        // Initialize a list to hold the integers
        List<Integer> as = new ArrayList<>();

        // Read n integers from input
        for (int i = 0; i < n; i++) {
            as.add(sc.nextInt());
        }

        // Initialize a list to hold the unique sorted integers
        List<Integer> xs = new ArrayList<>();
        xs.add(as.get(0));

        // Iterate through the input integers starting from the second element
        for (int j = 1; j < n; j++) {
            // Use binary search to find the position to insert the current integer
            int idx = Collections.binarySearch(xs, as.get(j));
            if (idx < 0) {
                // If not found, the insertion point is -(idx + 1)
                idx = -(idx + 1);
                xs.add(idx, as.get(j));
            }
        }

        // Print the number of unique integers found
        System.out.println(xs.size());
    }
}
// <END-OF-CODE>
