import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and the number of operations (M)
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Initialize a list to hold the elements
        List<Integer> L = new ArrayList<>(Collections.nCopies(100000, 0));
        int l;

        // Read N integers from input and store them in the list L
        for (int i = 0; i < N; i++) {
            l = scanner.nextInt();
            L.set(i, l);
        }

        // Sort the list L in ascending order
        Collections.sort(L.subList(0, N));

        // Perform M operations to modify the list L
        for (int i = 0; i < M; i++) {
            // Get the maximum element from the end of the sorted list
            int max_L = L.get(N - 1);
            
            // If the maximum element is 0, break the loop as no further operations are needed
            if (max_L == 0) {
                break;
            }

            // Halve the maximum element
            max_L /= 2;

            // Find the position to insert the halved value in the sorted list
            int pos = Collections.binarySearch(L.subList(0, N), max_L);
            if (pos < 0) {
                pos = -(pos + 1); // Convert to insertion point
            }

            // Insert the halved value into the list at the found position
            L.add(pos, max_L);
            
            // Remove the last element (the original maximum) from the list
            L.remove(N);
            N--; // Decrease the size of the effective list
        }

        // Calculate the sum of all elements in the list L
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += L.get(i);
        }

        // Output the final sum
        System.out.println(ans);
    }
}
// <END-OF-CODE>
