import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class MajorityElement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input n which represents the threshold for majority
        int n = scanner.nextInt();
        
        // Consume the newline character
        scanner.nextLine();
        
        // Read a line of input, split it into a list of strings, and store it in m
        String[] m = scanner.nextLine().split(" ");
        
        // Initialize a variable to track if a majority element is possible
        boolean possible = true;
        
        // Create a set of unique elements from the list m
        Set<String> uniqueElements = new HashSet<>();
        for (String element : m) {
            uniqueElements.add(element);
        }
        
        // Iterate through each unique element in the set
        for (String i : uniqueElements) {
            // Check if the count of the current element i is greater than or equal to n/2 + 1
            if (countOccurrences(m, i) >= n / 2 + 1) {
                // If it is, set possible to False and break the loop
                possible = false;
                break;
            }
        }
        
        // Print 'YES' if a majority element is not found, otherwise print 'NO'
        System.out.println(possible ? "YES" : "NO");
    }
    
    // Helper method to count occurrences of a string in an array
    private static int countOccurrences(String[] array, String target) {
        int count = 0;
        for (String element : array) {
            if (element.equals(target)) {
                count++;
            }
        }
        return count;
    }
}
