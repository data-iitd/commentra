import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to take input
        String S = scanner.nextLine();  // Take a string input from the user

        HashMap<Character, Integer> counter = new HashMap<>();  // Create a HashMap to count character frequencies
        for (char c : S.toCharArray()) {
            counter.put(c, counter.getOrDefault(c, 0) + 1);  // Count the frequency of each character
        }

        HashSet<Character> uniqueChars = new HashSet<>();  // Create a HashSet to store unique characters
        for (char c : S.toCharArray()) {
            uniqueChars.add(c);  // Add each character to the HashSet
        }

        // Check if the number of unique characters is not equal to 2
        if (uniqueChars.size() != 2) {
            System.out.println("No");  // Print "No" and exit if the condition is true
            return;  // Exit the program
        }

        // Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
        for (char c : uniqueChars) {
            if (counter.get(c) != 2) {
                System.out.println("No");  // Print "No" and exit if the condition is true
                return;  // Exit the program
            }
        }

        System.out.println("Yes");  // Print "Yes" if all characters have a frequency of 2
    }
}
// <END-OF-CODE>
