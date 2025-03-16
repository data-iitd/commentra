import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers `n` and `k` from the standard input, separated by a space
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        
        // Create a list of integers from the standard input, each line containing `n` integers
        int[] numbers = Arrays.stream(scanner.nextLine().split(" "))
                              .mapToInt(Integer::parseInt)
                              .toArray();
        
        // Sort the list in ascending order
        Arrays.sort(numbers);
        
        // Calculate the sum of the first `k` elements of the sorted list
        int result = 0;
        for (int i = 0; i < k; i++) {
            result += numbers[i];
        }
        
        // Print the result
        System.out.println(result);
    }
}
