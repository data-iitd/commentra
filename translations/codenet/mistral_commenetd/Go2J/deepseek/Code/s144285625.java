import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the number of elements in the array
        int n = scanner.nextInt();

        // Allocating memory for the array
        int[] ar = new int[3 * n];

        // Reading elements of the array
        for (int i = 0; i < 3 * n; i++) {
            // Reading next integer and storing it in the array
            ar[i] = scanner.nextInt();
        }

        // Sorting the array in ascending order
        Arrays.sort(ar);

        // Calculating the sum of elements at index 3n-2i-1 in the sorted array
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // Adding the element at index 3n-2i-1 to the sum
            sum += ar[3 * n - (i + 1) * 2];
        }

        // Printing the result
        System.out.println(sum);
    }
}
