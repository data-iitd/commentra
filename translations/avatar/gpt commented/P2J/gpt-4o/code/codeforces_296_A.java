import java.util.HashSet;
import java.util.Scanner;

public class MajorityElement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input n which represents the threshold for majority
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read a line of input, split it into a list of strings, and store it in m
        String[] m = scanner.nextLine().split(" ");
        
        // Initialize a variable to track if a majority element is possible
        boolean possible = true;
        
        // Use a HashSet to iterate through each unique element in the list m
        HashSet<String> uniqueElements = new HashSet<>();
        for (String element : m) {
            uniqueElements.add(element);
        }
        
        // Iterate through each unique element
        for (String i : uniqueElements) {
            // Check if the count of the current element i is greater than or equal to n/2 + 1
            int count = 0;
            for (String element : m) {
                if (element.equals(i)) {
                    count++;
                }
            }
            if (count >= n / 2 + 1) {
                // If it is, set possible to false and break the loop
                possible = false;
                break;
            }
        }
        
        // Print 'YES' if a majority element is not found, otherwise print 'NO'
        System.out.println(possible ? "YES" : "NO");
        
        scanner.close();
    }
}
// <END-OF-CODE>
