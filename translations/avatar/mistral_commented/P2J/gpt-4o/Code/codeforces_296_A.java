import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer 'n' as input from the user
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Take a list 'm' as input from the user, where each element is a single character
        String[] m = scanner.nextLine().split(" ");
        
        // Initialize a boolean variable 'possible' with a default value of true
        boolean possible = true;
        
        // Create a map to count occurrences of each character
        Map<String, Integer> countMap = new HashMap<>();
        
        // Count occurrences of each character
        for (String character : m) {
            countMap.put(character, countMap.getOrDefault(character, 0) + 1);
        }
        
        // Iterate through each unique character in the map
        for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
            String character = entry.getKey();
            int count = entry.getValue();
            
            // Check if the character appears more than 'n/2 + 1' times
            if (count >= n / 2 + 1) {
                // If the condition is true, set 'possible' to false and break the loop
                possible = false;
                break;
            }
        }
        
        // Print 'YES' if 'possible' is still true, otherwise print 'NO'
        System.out.println(possible ? "YES" : "NO");
        
        scanner.close();
    }
}

// <END-OF-CODE>
