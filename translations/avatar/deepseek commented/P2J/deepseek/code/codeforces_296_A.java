import java.util.Scanner;
import java.util.HashSet;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the threshold
        scanner.nextLine();  // Consume the newline character
        String[] m = scanner.nextLine().split(" ");  // Take a space-separated string input and split it into an array
        boolean possible = true;  // Initialize a boolean variable to check if the condition is possible

        // Create a HashSet to store unique elements
        HashSet<String> uniqueElements = new HashSet<>();
        for (String element : m) {
            uniqueElements.add(element);
        }

        // Create a HashMap to count occurrences of each element
        HashMap<String, Integer> countMap = new HashMap<>();
        for (String element : m) {
            countMap.put(element, countMap.getOrDefault(element, 0) + 1);
        }

        // Iterate over the unique elements in the HashSet
        for (String i : uniqueElements) {
            // Check if the count of the current element is greater than or equal to n / 2 + 1
            if (countMap.get(i) >= n / 2 + 1) {
                possible = false;  // Set possible to False if the condition is met
                break;  // Break the loop as the condition is already not possible
            }
        }

        // Print 'YES' if possible is True, otherwise print 'NO'
        System.out.println(possible ? "YES" : "NO");
    }
}
