import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        String s = scanner.nextLine();
        
        int[] count = new int[26]; // Initialize an array to count occurrences of each letter
        
        for (char c : s.toCharArray()) {
            count[c - 'A']++; // Increment the count for the corresponding character
        }
        
        Arrays.sort(count); // Sort the count array in ascending order
        
        int res = 0; // Initialize res to 0
        
        for (int i = 25; i >= 0; i--) { // Iterate from the end of the sorted array
            if (count[i] >= k) {
                res += k * k; // Calculate the result using k * k
                System.out.println(res); // Print the result
                return; // Exit the program
            }
            
            k -= count[i]; // Subtract the current count from k
            res += count[i] * count[i]; // Add the square of the current count to res
        }
        
        System.out.println(res); // Print the final result
    }
}
// <END-OF-CODE>
