import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input from user
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Initialize a list of integers
        List<Integer> L = new ArrayList<>(N);

        // Read integers from user and store them in the list
        for (int i = 0; i < N; i++) {
            L.add(scanner.nextInt());
        }

        // Sort the list in ascending order
        Collections.sort(L);

        // Perform the required operations for M times
        for (int i = 0; i < M; i++) {
            int max_L = L.get(L.size() - 1); // Get the last element of the list

            // If the last element is 0, break the loop
            if (max_L == 0) {
                break;
            }

            // Divide the last element by 2
            max_L /= 2;

            // Find the position of the element greater than or equal to max_L using binary search
            int index = Collections.binarySearch(L, max_L);
            if (index < 0) {
                index = -(index + 1); // Convert to insertion point
            }

            // Insert max_L before the found position and remove the last element
            L.add(index, max_L);
            L.remove(L.size() - 1);
        }

        // Calculate the answer and print it
        long ans = 0;
        for (int num : L) {
            ans += num;
        }
        System.out.println(ans);
    }
}

// <END-OF-CODE>
