import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // This line takes two integers, n and k, as input from the user.
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // This line takes the list of integers input in the next line.
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        
        // Sort the array
        Arrays.sort(numbers);
        
        // This line prints the sum of the first k smallest numbers.
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += numbers[i];
        }
        
        System.out.println(sum);
        scanner.close();
    }
}
// <END-OF-CODE>
