import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
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
        for (int value : w) {
            x += value;
        }

        // Initialize a list to store indices
        List<Integer> d = new ArrayList<>();

        // Iterate through each element in the list
        for (int i = 0; i < n; i++) {
            // Check if removing the current element results in an average equal to the current element
            if ((x - w[i]) / (double)(n - 1) == w[i]) {
                // If the condition is met, append the 1-based index to the list
                d.add(i + 1);
            }
        }

        // Print the number of valid indices found
        System.out.println(d.size());

        // Print the valid indices as a space-separated string
        for (int i = 0; i < d.size(); i++) {
            System.out.print(d.get(i));
            if (i < d.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
        
        scanner.close();
    }
}
// <END-OF-CODE>
