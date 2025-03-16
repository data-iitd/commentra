import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty list `L`
        List<Integer> L = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);

        // Read the first input, which is the number of elements to add to the list
        int n = scanner.nextInt();
        int r = 1; // Initialize r to 1

        // Use a for loop to iterate through each integer in the input
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            // Add `r` elements to the list `L` with the value `r`
            for (int j = 0; j < k; j++) {
                L.add(r);
            }
            // Increment the value of `r` by 1 to prepare for the next iteration
            r++;
        }

        // Read the second input, which represents the indices of the elements to print from the list
        int m = scanner.nextInt();

        // Use another for loop to iterate through each integer in the input
        for (int i = 0; i < m; i++) {
            int j = scanner.nextInt();
            // Print the element at the given index using the index as an offset from the beginning of the list
            System.out.println(L.get(j - 1));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
