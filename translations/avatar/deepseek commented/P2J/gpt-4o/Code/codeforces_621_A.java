import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Read the number of elements in the list
        int[] lst = new int[n];  // Initialize the array
        
        for (int i = 0; i < n; i++) {
            lst[i] = scanner.nextInt();  // Read the list of integers
        }
        
        Arrays.sort(lst);  // Sort the array in ascending order
        
        // Reverse the array to get descending order
        for (int i = 0; i < n / 2; i++) {
            int temp = lst[i];
            lst[i] = lst[n - 1 - i];
            lst[n - 1 - i] = temp;
        }

        // Initialize a counter for odd numbers
        int od = 0;
        for (int i : lst) {
            if (i % 2 != 0) {  // Check if the number is odd
                od++;
            }
        }

        // Initialize sum to accumulate the result
        int sum = 0;
        boolean ok = false;  // Initialize a flag to track if an odd number has been added

        // Iterate through the list to process each number
        for (int i = 0; i < n; i++) {
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
        scanner.close();
    }
}
// <END-OF-CODE>
