import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Reading the number of elements (n)
        int n = Integer.parseInt(scanner.nextLine());

        // Step 2: Reading the list of elements (a)
        int[] a = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();

        // Step 3: Initializing variables
        int pre = Integer.MAX_VALUE;  // Initialize pre to infinity
        int ans = 0;  // Initialize ans to 0

        // Step 4: Sorting the list in descending order
        Arrays.sort(a);
        for (int i = n - 1; i >= 0; i--) {
            a[i] = Math.min(pre - 1, a[i]);
            ans += Math.max(0, a[i]);
            pre = Math.max(0, a[i]);
        }

        // Step 6: Printing the result
        System.out.println(ans);
    }
}
