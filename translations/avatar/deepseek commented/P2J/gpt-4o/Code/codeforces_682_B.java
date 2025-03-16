import java.util.Arrays;
import java.util.Scanner;

public class UniqueElements {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();
        int[] l = new int[n];

        // Read the list of elements
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }

        // Initialize variables
        int f = 1;  // Flag variable
        Arrays.sort(l);  // Sort the list
        int c = 0;  // Counter variable

        // Iterate through the list to find the maximum number of unique elements
        for (int i : l) {
            if (i > c) {
                c++;  // Increment the counter if the current element is greater than the counter
            }
        }

        // Print the result
        System.out.println(c + 1);  // Print the maximum number of unique elements

        scanner.close();
    }
}

// <END-OF-CODE>
