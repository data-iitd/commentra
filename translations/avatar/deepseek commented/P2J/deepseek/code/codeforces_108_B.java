import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Take input from the user
        scanner.nextLine();
        // Read the input, split it into a list of integers, and store it in 'a'
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        // Sort the array 'a'
        Arrays.sort(a);
        // Iterate through the sorted array starting from the second element
        for (int i = 1; i < a.length; i++) {
            // Check if the current element is not equal to the previous element
            // and if the current element is less than twice the previous element
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                // If the condition is met, print 'YES' and return
                System.out.println("YES");
                return;
            }
        }
        // If the loop completes without finding a match, print 'NO'
        System.out.println("NO");
    }
}
