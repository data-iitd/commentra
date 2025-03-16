import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        List<Integer> ar = new ArrayList<>(3 * n); // Create a list of size 3*n
        for (int i = 0; i < 3 * n; i++) {
            ar.add(scanner.nextInt()); // Populate the list with integers from input
        }
        Collections.sort(ar); // Sort the list
        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < n; i++) {
            sum += ar.get(3 * n - (i + 1) * 2); // Calculate the sum of the last n elements, skipping every second element
        }
        System.out.println(sum); // Print the sum
    }
}
