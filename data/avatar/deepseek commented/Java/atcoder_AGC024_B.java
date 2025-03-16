import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt(); // Read the number of elements in the array P
        int[] P = new int[N]; // Initialize the array P with N elements
        for (int i = 0; i < N; ++i) {
            P[i] = scan.nextInt() - 1; // Read each element and adjust to 0-based index
        }

        // Create a HashMap to map each value in P to its index
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < N; ++i) {
            map.put(P[i], i);
        }

        // Create a list to store indices of elements that are out of order
        List<Integer> nglist = new ArrayList<>();
        for (int i = 0; i < N - 1; ++i) {
            if (map.get(i) > map.get(i + 1)) {
                nglist.add(i); // Add the index to nglist if the current element is greater than the next element
            }
        }

        // If nglist is empty, the array P is already sorted
        if (nglist.isEmpty()) {
            System.out.println(0); // Print 0 and return as the array is sorted
            return;
        }

        // Calculate the minimum number of swaps required to sort the array P
        int ans = Math.min(N - nglist.get(0) - 1, nglist.get(nglist.size() - 1) + 1);
        for (int i = 0; i < nglist.size() - 1; ++i) {
            ans = Math.min(nglist.get(i) + 1 + N - nglist.get(i + 1) - 1, ans);
        }

        // Print the minimum number of swaps required
        System.out.println(ans);
    }
}
