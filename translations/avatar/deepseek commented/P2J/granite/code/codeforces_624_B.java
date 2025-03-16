
import java.util.*;

public class codeforces_624_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Step 1: Reading the number of elements (n)
        int n = sc.nextInt();

        // Step 2: Reading the list of elements (a)
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        // Step 3: Initializing variables
        int pre = Integer.MAX_VALUE;  // Initialize pre to maximum integer value
        int ans = 0;  // Initialize ans to 0

        // Step 4: Sorting the list in descending order
        Collections.sort(a, Collections.reverseOrder());

        // Step 5: Iterating through the list
        for (int j = 0; j < n; j++) {
            // Calculate the maximum value that can be added to ans
            ans += Math.max(0, Math.min(pre - 1, a.get(j)));
            // Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
            pre = Math.max(0, Math.min(pre - 1, a.get(j)));
        }

        // Step 6: Printing the result
        System.out.println(ans);
    }
}
