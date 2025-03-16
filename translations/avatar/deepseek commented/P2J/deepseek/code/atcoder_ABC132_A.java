import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();  // Take a string input from the user
        Map<Character, Integer> c = new HashMap<>();  // Count the frequency of each character in the string S
        Set<Character> Sa = new HashSet<>();  // Convert the string S into a set of unique characters

        // Count the frequency of each character in the string S
        for (char ch : S.toCharArray()) {
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }

        // Convert the string S into a set of unique characters
        for (char ch : S.toCharArray()) {
            Sa.add(ch);
        }

        // Check if the number of unique characters is not equal to 2
        if (Sa.size() != 2) {
            System.out.println("No");  // Print "No" and exit if the condition is true
            return;  // Exit the program
        }

        // Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
        for (char ch : Sa) {
            if (c.get(ch) != 2) {
                System.out.println("No");  // Print "No" and exit if the condition is true
                return;  // Exit the program
            }
        }

        System.out.println("Yes");  // Print "Yes" if all characters have a frequency of 2
    }
}
