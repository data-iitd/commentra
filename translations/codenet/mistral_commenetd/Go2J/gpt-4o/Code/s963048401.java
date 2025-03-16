import java.util.*;

public class Main {
    // Initialize the modulus value
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Initialize the scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array
        int n = sc.nextInt();

        // Initialize an array to store the elements
        int[] as = new int[n];

        // Read the elements of the array into the as array
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }

        // Initialize a list to store the unique elements
        List<Integer> xs = new ArrayList<>();
        xs.add(as[0]);

        // Iterate through the array and add unique elements to the xs list
        for (int j = 1; j < n; j++) {
            // Binary search to find the index where the current element should be inserted in the xs list
            int idx = Collections.binarySearch(xs, as[j]);

            // If the current element is not already present in the xs list, append it
            if (idx < 0) {
                xs.add(-idx - 1, as[j]); // Insert at the correct position
            }
        }

        // Print the length of the xs list
        System.out.println(xs.size());
    }
}
// <END-OF-CODE>
