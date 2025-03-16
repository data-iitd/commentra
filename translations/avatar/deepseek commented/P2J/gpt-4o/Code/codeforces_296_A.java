import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Take an integer input representing the threshold
        scanner.nextLine();  // Consume the newline character
        String[] m = scanner.nextLine().split(" ");  // Take a space-separated string input and split it into a list
        
        boolean possible = true;  // Initialize a boolean variable to check if the condition is possible
        
        // Use a HashSet to iterate over the unique elements in the array `m`
        HashSet<String> uniqueElements = new HashSet<>();
        for (String element : m) {
            uniqueElements.add(element);
        }
        
        // Iterate over the unique elements
        for (String i : uniqueElements) {
            // Check if the count of the current element is greater than or equal to n / 2 + 1
            int count = 0;
            for (String element : m) {
                if (element.equals(i)) {
                    count++;
                }
            }
            if (count >= n / 2 + 1) {
                possible = false;  // Set possible to False if the condition is met
                break;  // Break the loop as the condition is already not possible
            }
        }
        
        // Print 'YES' if possible is True, otherwise print 'NO'
        System.out.println(possible ? "YES" : "NO");
        
        scanner.close();
    }
}
// <END-OF-CODE>
