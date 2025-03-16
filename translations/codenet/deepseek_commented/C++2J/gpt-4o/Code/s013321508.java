import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // Reading two integers, N and M.
        int M = scanner.nextInt();

        List<Integer> L = new ArrayList<>(Collections.nCopies(100000, 0)); // Initializing a list L with a size of 100,000.
        for (int i = 0; i < N; i++) {
            L.set(i, scanner.nextInt()); // Reading N integers and populating the list L.
        }

        Collections.sort(L.subList(0, N)); // Sorting the list L in ascending order.

        for (int i = 0; i < M; i++) { // Performing M operations.
            int max_L = L.get(N - 1); // Finding the largest element in the list.
            if (max_L == 0) {
                break; // If the largest element is 0, break the loop.
            }

            max_L /= 2; // Halving the largest element.
            int index = Collections.binarySearch(L.subList(0, N), max_L); // Finding the position to insert the halved value.
            if (index < 0) {
                index = -(index + 1); // If not found, get the insertion point.
            }
            L.add(index, max_L); // Inserting the halved value back into the list.
            L.remove(N); // Removing the largest element from the list.
            N--; // Decrease the size of the effective list.
        }

        long ans = 0; // Initialize the sum.
        for (int i = 0; i < N; i++) {
            ans += L.get(i); // Calculating the sum of all elements in the list L.
        }

        System.out.println(ans); // Printing the result.
    }
}
// <END-OF-CODE>
