import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an input line (not used in the logic)
        scanner.nextLine();
        
        // Read a line of integers, split by spaces, and convert them to an array of integers
        int[] a = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        // Sort the array of integers in ascending order
        Arrays.sort(a);
        
        // Iterate through the sorted array starting from the second element
        for (int i = 1; i < a.length; i++) {
            // Check if the current element is different from the previous one
            // and if it is less than double the previous element
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                // If the condition is met, print "YES" and return
                System.out.println("YES");
                return;
            }
        }
        
        // If no such pair is found, print "NO"
        System.out.println("NO");
    }
}
