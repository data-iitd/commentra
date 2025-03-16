import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input which are two integers 'num' and 'k'
        int num = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Initialize 'num' and 'k' with the values from user input
        
        // Read the second line of input which is a list 'arr' of integers
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Initialize an empty set 'different' to store unique integers
        Set<Integer> different = new HashSet<>();
        
        // Sort the array 'arr' in ascending order
        Arrays.sort(arr);
        
        // Iterate through each integer 'x' in the sorted array 'arr'
        int temp = 0;
        for (int x : arr) {
            // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
            if (x % k != 0 || !different.contains(x / k)) {
                // If the condition is true, add 'x' to the set 'different'
                different.add(x);
                // Update the maximum length of 'different' seen so far
                temp = Math.max(different.size(), temp);
            }
        }
        
        // Print the maximum length of 'different'
        System.out.println(temp);
    }
}

