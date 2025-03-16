import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input for the number of elements
        int n = scanner.nextInt();
        
        // Read a list of integers from input
        int[] lst = new int[n];
        for (int i = 0; i < n; i++) {
            lst[i] = scanner.nextInt();
        }
        
        // Sort the list in ascending order
        Arrays.sort(lst);
        
        // Reverse the list to get it in descending order
        for (int i = 0; i < n / 2; i++) {
            int temp = lst[i];
            lst[i] = lst[n - 1 - i];
            lst[n - 1 - i] = temp;
        }
        
        // Initialize a counter for odd numbers
        int od = 0;
        
        // Count the number of odd integers in the list
        for (int i : lst) {
            if ((i & 1) == 1) {  // Check if the number is odd using bitwise AND
                od++;  // Increment the odd counter
            }
        }
        
        // Initialize variables for sum and a flag to track even number inclusion
        int sum = 0;
        boolean ok = false;
        
        // Iterate through the sorted list to calculate the desired sum
        for (int i = 0; i < n; i++) {
            if (lst[i] % 2 == 0) {  // Check if the current number is even
                sum += lst[i];  // Add even numbers directly to the sum
            } else {
                // If we have already included an odd number or there is more than one odd number left
                if (ok || od > 1) {
                    sum += lst[i];  // Add the odd number to the sum
                    od--;  // Decrement the odd counter
                    ok = !ok;  // Toggle the flag to indicate an odd number has been included
                }
            }
        }
        
        // Print the final calculated sum
        System.out.println(sum);
        
        scanner.close();
    }
}
// <END-OF-CODE>
