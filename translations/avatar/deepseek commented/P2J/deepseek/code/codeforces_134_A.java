import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the list `w`
        int n = Integer.parseInt(scanner.nextLine());

        // Read `n` integers from the standard input and store them in the list `w`
        String[] wStr = scanner.nextLine().split(" ");
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(wStr[i]);
        }

        // Calculate the sum of all elements in the list `w`
        int x = 0;
        for (int num : w) {
            x += num;
        }

        // Initialize an empty list `d` to store the indices of elements that satisfy the condition
        List<Integer> d = new ArrayList<>();

        // Iterate over each element in the list `w`
        for (int i = 0; i < n; i++) {
            // Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
            if ((x - w[i]) * 1.0 / (n - 1) == w[i]) {
                // Append the 1-based index of the element to the list `d`
                d.add(i + 1);
            }
        }

        // Print the length of the list `d`
        System.out.println(d.size());

        // Print the indices in `d` separated by spaces
        for (int i = 0; i < d.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(d.get(i));
        }
        System.out.println();
    }
}
