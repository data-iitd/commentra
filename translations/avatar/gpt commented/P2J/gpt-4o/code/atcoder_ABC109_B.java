import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initialize a HashMap to count occurrences of each string
        Map<String, Integer> countMap = new HashMap<>();
        
        // Read n strings into a list
        List<String> strings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            strings.add(scanner.nextLine());
        }
        
        // Initialize a flag to determine if the conditions are met
        String result = "Yes";
        
        // Initialize an index variable to track the previous string
        int previousIndex = -1;
        
        // Iterate through each string in the list
        for (int i = 0; i < strings.size(); i++) {
            String currentString = strings.get(i);
            
            // Increment the count for the current string
            countMap.put(currentString, countMap.getOrDefault(currentString, 0) + 1);
            
            // Check if the current string has appeared more than once
            if (countMap.get(currentString) >= 2) {
                result = "No";  // Set flag to 'No' if a duplicate is found
            }
            
            // Check if the previous string's last character does not match the current string's first character
            if (previousIndex != -1 && strings.get(previousIndex).charAt(strings.get(previousIndex).length() - 1) != currentString.charAt(0)) {
                result = "No";  // Set flag to 'No' if the character condition is violated
            }
            
            // Update the index to the current string's index
            previousIndex = i;
        }
        
        // Print the final result based on the checks
        System.out.println(result);
        
        scanner.close();
    }
}
// <END-OF-CODE>
