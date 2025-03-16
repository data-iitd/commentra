import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input: num (number of elements) and k (the divisor)
        int num = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the array of integers from input
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Initialize a set to keep track of unique elements that meet the criteria
        Set<Integer> different = new HashSet<>();
        
        // Initialize a variable to keep track of the maximum size of the 'different' set
        int temp = 0;
        
        // Sort the array to process elements in ascending order
        Arrays.sort(arr);
        
        // Iterate through each element in the sorted array
        for (int x : arr) {
            // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
            if (x % k != 0 || !different.contains(x / k)) {
                // Add the element to the 'different' set since it meets the criteria
                different.add(x);
            }
            
            // Update the maximum size of the 'different' set if the current size is larger
            temp = Math.max(different.size(), temp);
        }
        
        // Print the maximum size of the 'different' set found
        System.out.println(temp);
        
        scanner.close();
    }
}
// <END-OF-CODE>
