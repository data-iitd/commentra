import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements and the divisor
        int num = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the array of integers
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Initialize a set to keep track of unique elements not divisible by k
        Set<Integer> different = new HashSet<>();
        int temp = 0;  // Initialize a variable to store the maximum length of the set
        
        // Sort the array
        Arrays.sort(arr);
        
        // Iterate through each element in the sorted array
        for (int x : arr) {
            if (x % k != 0 || !different.contains(x / k)) {  // Check if x is not divisible by k or x/k is not in the set
                different.add(x);  // Add x to the set if the condition is true
            }
            temp = Math.max(different.size(), temp);  // Update temp with the maximum length of the set
        }
        
        System.out.println(temp);  // Print the maximum number of unique elements not divisible by k
    }
}
// <END-OF-CODE>
