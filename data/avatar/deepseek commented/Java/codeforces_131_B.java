
import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Initialize Scanner object to read input
        int n = scan.nextInt(); // Read the number of elements
        int N = (int) 1e5 + 5; // Define a constant N for array size
        long[] cnt = new long[21]; // Initialize an array to count occurrences of each value shifted by 10

        // Count the occurrences of each value shifted by 10
        for (int i = 0; i < n; i++) {
            cnt[scan.nextInt() + 10]++;
        }

        long res = 0; // Initialize result variable

        // Calculate the number of pairs that sum up to 20
        for (int i = 0; i < 10; i++) {
            res += cnt[i] * cnt[20 - i];
        }

        // Special case for pairs where both elements are the same (i.e., i = 10)
        res += (cnt[10] * (cnt[10] - 1)) / 2;

        // Output the result
        System.out.println(res);
    }
}
