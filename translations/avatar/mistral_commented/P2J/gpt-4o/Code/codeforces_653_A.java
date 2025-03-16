import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Read the number of elements in the list
        int[] l = new int[n];  // Create an array to hold the integers
        
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();  // Read the integers into the array
        }
        
        Arrays.sort(l);  // Sort the array in ascending order
        
        boolean found = false;  // Flag to check if the condition is met
        
        for (int i = 0; i < n; i++) {  // Iterate through each element in the sorted array
            if (Arrays.binarySearch(l, l[i] + 1) >= 0 && Arrays.binarySearch(l, l[i] + 2) >= 0) {  // Check if the next two elements are also in the array
                System.out.println("YES");  // If yes, print 'YES' and set found to true
                found = true;
                break;
            }
        }
        
        if (!found) {
            System.out.println("NO");  // If no, print 'NO' after the loop finishes
        }
        
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
