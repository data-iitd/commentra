import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements in the list
        int n = scanner.nextInt();
        
        // Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the list in ascending order
        Arrays.sort(l);
        
        // Iterate through each element in the sorted list
        for (int i = 0; i < n; i++) {
            // Check if both i + 1 and i + 2 exist in the list
            if (Arrays.stream(l).anyMatch(x -> x == l[i] + 1) && Arrays.stream(l).anyMatch(x -> x == l[i] + 2)) {
                // If the condition is met, print 'YES' and exit the loop
                System.out.println("YES");
                return;
            }
        }
        
        // If the loop completes without finding the condition, print 'NO'
        System.out.println("NO");
    }
}
