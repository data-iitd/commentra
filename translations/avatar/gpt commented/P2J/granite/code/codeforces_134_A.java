
import java.util.Scanner;

public class codeforces_134_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Read the list of integers
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        // Calculate the sum of the list
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }

        // Initialize an empty list to store indices
        int[] d = new int[n];
        int count = 0;

        // Iterate through each element in the list
        for (int i = 0; i < n; i++) {
            // Check if removing the current element results in an average equal to the current element
            if ((x - w[i]) / (n - 1) == w[i]) {
                // If the condition is met, append the 1-based index to the list
                d[count] = i + 1;
                count++;
            }
        }

        // Print the number of valid indices found
        System.out.println(count);

        // Print the valid indices as a space-separated string
        for (int i = 0; i < count; i++) {
            System.out.print(d[i] + " ");
        }
    }
}
