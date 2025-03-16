import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of groups of three integers
        int n = scanner.nextInt();

        // Initialize a list to hold 3*n integers
        List<Integer> ar = new ArrayList<>();

        // Populate the list with integers from input
        for (int i = 0; i < 3 * n; i++) {
            ar.add(scanner.nextInt());
        }

        // Sort the list of integers in ascending order
        Collections.sort(ar);

        // Initialize a variable to hold the sum of selected integers
        int sum = 0;

        // Calculate the sum of the second largest integer from each group of three
        for (int i = 0; i < n; i++) {
            sum += ar.get(3 * n - (i + 1) * 2); // Select the second largest integer from the sorted list
        }

        // Print the final computed sum
        System.out.println(sum);
    }
}
