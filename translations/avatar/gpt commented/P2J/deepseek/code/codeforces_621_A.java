import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input for the number of elements
        int n = scanner.nextInt();
        
        // Read a list of integers from input and convert them to an array of integers
        int[] lst = new int[n];
        for (int i = 0; i < n; i++) {
            lst[i] = scanner.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(lst);
        
        // Reverse the array to get it in descending order
        reverseArray(lst);
        
        // Initialize a counter for odd numbers
        int od = 0;
        
        // Count the number of odd integers in the array
        for (int i : lst) {
            if (i % 2 != 0) {  // Check if the number is odd
                od++;  // Increment the odd counter
            }
        }
        
        // Initialize variables for sum and a flag to track even number inclusion
        int sum = 0;
        boolean ok = false;
        
        // Iterate through the sorted array to calculate the desired sum
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
    }
    
    // Helper method to reverse an array
    public static void reverseArray(int[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            // Swap the elements at left and right indices
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}
