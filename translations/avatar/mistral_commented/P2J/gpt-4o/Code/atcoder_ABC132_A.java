import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take a string as input from the user
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Create a set Sa from the characters in the string S
        HashSet<Character> Sa = new HashSet<>();
        for (char c : S.toCharArray()) {
            Sa.add(c);
        }

        // Check if the length of the set Sa is equal to 2
        if (Sa.size() != 2) {
            // If not, print "No" and exit the program
            System.out.println("No");
            return;
        }

        // Create a frequency map to count the occurrences of each character
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : S.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Iterate through each character i in the set Sa
        for (char i : Sa) {
            // Check if its frequency in the string S is equal to 2
            if (frequencyMap.get(i) != 2) {
                // If the frequency of any character is not equal to 2, print "No" and exit the program
                System.out.println("No");
                return;
            }
        }

        // If all characters have a frequency of 2, print "Yes"
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
