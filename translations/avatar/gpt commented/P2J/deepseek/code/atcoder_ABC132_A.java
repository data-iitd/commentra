import java.util.Scanner;
import java.util.HashMap;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Create a HashMap to count occurrences of each character
        HashMap<Character, Integer> c = new HashMap<>();

        // Populate the HashMap with character counts
        for (char ch : S.toCharArray()) {
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }

        // Create a HashSet to store unique characters
        HashSet<Character> Sa = new HashSet<>();

        // Add each character from the input string to the HashSet
        for (char ch : S.toCharArray()) {
            Sa.add(ch);
        }

        // Check if the number of unique characters is not equal to 2
        if (Sa.size() != 2) {
            // If there are not exactly 2 unique characters, print "No" and exit
            System.out.println("No");
            return;
        }

        // Check if each unique character appears exactly twice
        for (char ch : Sa) {
            if (c.get(ch) != 2) {
                // If any character does not appear exactly twice, print "No" and exit
                System.out.println("No");
                return;
            }
        }

        // If both conditions are satisfied, print "Yes"
        System.out.println("Yes");
    }
}
