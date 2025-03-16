import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // mod is a global variable for storing a modulus value
    static int mod;

    // main function initializes the modulus value and reads the number of elements
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        mod = 1000000007;

        int n = scanner.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
        }

        // Initialize xs with the first element of as
        List<Integer> xs = new ArrayList<>();
        xs.add(as[0]);
        for (int j = 1; j < n; j++) {
            // Use binary search to find the position to insert the current element
            int idx = binarySearch(xs, as[j]);
            if (idx == xs.size()) {
                // If the element is larger than all elements in xs, append it
                xs.add(as[j]);
            } else {
                // Otherwise, replace the existing element at the found position
                xs.set(idx, as[j]);
            }
        }

        // Print the length of the longest increasing subsequence found
        System.out.println(xs.size());
    }

    // binarySearch finds the index where the value should be inserted
    private static int binarySearch(List<Integer> xs, int value) {
        int low = 0, high = xs.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (xs.get(mid) < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
// <END-OF-CODE>
