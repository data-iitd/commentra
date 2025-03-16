import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements in the list
        int n = scanner.nextInt();
        
        // Read the elements into an array
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(l);
        
        // Iterate through each element in the sorted array
        for (int i : l) {
            // Check if both i + 1 and i + 2 exist in the array
            if (Arrays.binarySearch(l, i + 1) >= 0 && Arrays.binarySearch(l, i + 2) >= 0) {
                // If the condition is met, print 'YES' and exit the loop
                System.out.println("YES");
                return;
            }
        }
        
        // If the loop completes without finding the condition, print 'NO'
        System.out.println("NO");
        
        scanner.close();
    }
}
// <END-OF-CODE>
