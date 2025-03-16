import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty list `L`
        ArrayList<Integer> L = new ArrayList<>();

        // Read the first input, which is the number of elements to add to the list
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Use a for loop to iterate through each integer in the input
        for (int i = 0; i < n; i++) {
            // Read the next input, which is the value to add to the list
            int r = scanner.nextInt();
            // Add `r` elements to the list `L` with the value `r`
            for (int j = 0; j < r; j++) {
                L.add(r);
            }
        }

        // Read the second input, which represents the indices of the elements to print from the list
        int m = scanner.nextInt();

        // Use another for loop to iterate through each integer in the input
        for (int i = 0; i < m; i++) {
            // Read the next input, which is the index of the element to print
            int index = scanner.nextInt();
            // Print the element at the given index using the index as an offset from the beginning of the list
            System.out.println(L.get(index - 1));
        }
    }
}
