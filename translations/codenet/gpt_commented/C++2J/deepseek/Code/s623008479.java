import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int k = scanner.nextInt(); // Read the number of largest elements to sum

        int[] l = new int[n]; // Create an array to store the elements
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt(); // Read each element into the array
        }

        Arrays.sort(l); // Sort the array in ascending order

        int ans = 0; // Initialize a variable to hold the sum of the largest k elements
        for (int i = 0; i < k; i++) {
            ans += l[n - 1 - i]; // Add the largest k elements to ans
        }

        System.out.println(ans); // Output the result
    }
}
