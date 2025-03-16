import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define constants
    static final int MAXN = 200000 + 10; // Maximum number of elements
    static final int INF = (int) 1e8; // A large value representing infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;

        while (scanner.hasNextInt()) { // Read the number of elements
            n = scanner.nextInt();
            int[] maps = new int[n + 1];
            int[] num = new int[n + 1];

            // Read the elements into maps array and copy them to num array
            for (int i = 1; i <= n; i++) {
                maps[i] = scanner.nextInt();
                num[i] = maps[i];
            }

            // Sort the maps array to find the median easily
            Arrays.sort(maps, 1, n + 1);

            // Calculate the median index
            int m = n / 2;

            // Iterate through the num array and print the appropriate median value
            for (int i = 1; i <= n; i++) {
                if (num[i] <= maps[m]) {
                    System.out.println(maps[m + 1]); // Print the element after the median if num[i] is less than or equal to the median
                } else {
                    System.out.println(maps[m]); // Print the median if num[i] is greater than the median
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
