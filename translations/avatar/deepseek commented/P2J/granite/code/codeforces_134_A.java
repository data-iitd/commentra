

import java.util.Scanner;

public class codeforces_134_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the list `w`
        int n = scanner.nextInt();

        // Read `n` integers from the standard input and store them in the list `w`
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        // Calculate the sum of all elements in the list `w`
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }

        // Initialize an empty list `d` to store the indices of elements that satisfy the condition
        List<Integer> d = new ArrayList<>();

        // Iterate over each element in the list `w`
        for (int i = 0; i < n; i++) {
            // Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
            if ((x - w[i]) / (n - 1) == w[i]) {
                // Append the 1-based index of the element to the list `d`
                d.add(i + 1);
            }
        }

        // Print the length of the list `d`
        System.out.println(d.size());

        // Print the indices in `d` separated by spaces
        for (int i = 0; i < d.size(); i++) {
            System.out.print(d.get(i) + " ");
        }
    }
}
