import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in the list
        int[] lst = new int[n];  // Create an array to store the list of integers
        for (int i = 0; i < n; i++) {
            lst[i] = scanner.nextInt();  // Read the list of integers
        }
        Arrays.sort(lst);  // Sort the array in ascending order
        int od = 0;  // Initialize a counter for odd numbers
        for (int i : lst) {
            if (i % 2 != 0) {  // Check if the number is odd
                od++;
            }
        }
        int sum = 0;  // Initialize sum to accumulate the result
        boolean ok = false;  // Initialize a flag to track if an odd number has been added
        for (int i = n - 1; i >= 0; i--) {  // Iterate through the array in descending order
            if (lst[i] % 2 == 0) {  // Check if the number is even
                sum += lst[i];  // Add even numbers to sum
            } else {
                if (ok || od > 1) {  // Check if an odd number can be added
                    sum += lst[i];  // Add odd number to sum
                    od--;  // Decrement the count of odd numbers
                    ok = !ok;  // Toggle the flag
                }
            }
        }
        System.out.println(sum);  // Print the final sum
    }
}

