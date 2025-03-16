import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers `n` and `k` from the standard input, separated by a space
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Create an array of integers from the standard input
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(numbers);
        
        // Calculate the sum of the first `k` elements of the sorted array
        int result = 0;
        for (int i = 0; i < k; i++) {
            result += numbers[i];
        }
        
        // Print the result
        System.out.println(result);
        
        scanner.close();
    }
}

// <END-OF-CODE>
