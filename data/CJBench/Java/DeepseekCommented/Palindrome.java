
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    // Step 1: Define the `isMain` method
    // This method checks if a given word is a palindrome.
    public static boolean isMain(String word) {
        return isMain(word, false);
    }

    // Step 2: Define the `isMainIgnoreCase` method
    // This method is a wrapper for `isMain` that ignores case.
    public static boolean isMainIgnoreCase(String word) {
        return isMain(word, true);
    }

    // Step 3: Define the `isMain` method with a boolean to ignore case
    // This private method checks if a given word is a palindrome, considering case sensitivity.
    private static boolean isMain(String word, boolean ignoreCase) {
        if (word == null) {
            return false;
        }
        if (ignoreCase) {
            word = word.toLowerCase();
        }
        for (int i = 0; i < word.length() / 2; i++) {
            if (word.charAt(i) != word.charAt(word.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    // Step 4: Define the `removeMains` method
    // This method removes all palindromic words from a given string.
    public static String removeMains(String string) {
        String[] words = string.split(",?\\s+");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            if (!isMainIgnoreCase(word)) {
                if (result.length() > 0) {
                    result.append(", ");
                }
                result.append(word);
            }
        }
        return result.toString();
    }

    // Step 5: Define the `removeNthMain` method
    // This method removes the nth palindromic word from a given string.
    public static String removeNthMain(String string, int n) {
        String[] words = string.split(",?\\s+");
        int counter = 0;
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            if (isMainIgnoreCase(word)) {
                counter++;
                if (counter == n) {
                    continue;
                }
            }
            if (result.length() > 0) {
                result.append(", ");
            }
            result.append(word);
        }
        return result.toString();
    }

    // Step 6: Define the `longestMainSubstring` method
    // This method finds the longest substring that is a palindrome in a given string.
    public static String longestMainSubstring(String str) {
        var result = str.substring(0, 1);
        for (int i = 0; i < str.length(); i++) {
            for (int j = str.length() - 1; j >= i + result.length() + 1; j--) {
                var currentString = str.substring(i, j);
                if (currentString.length() > result.length() && isMain(currentString)) {
                    result = currentString;
                }
            }
        }
        return result;
    }

    // Step 7: Define the `canFormMain` method
    // This method checks if a given string can be rearranged to form a palindrome.
    public static boolean canFormMain(String str) {
        Set<Character> set = new HashSet<>();
        for (var ch : str.toCharArray()) {
            if (!set.contains(ch)) {
                set.add(ch);
            } else {
                set.remove(ch);
            }
        }
        return set.size() <= 1;
    }

    // Step 7: Implement the main method
    // This method provides a menu-driven interface to interact with the user and call the appropriate methods based on the user's choice.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int option = sc.nextInt();
        sc.nextLine(); 
        switch (option) {
            case 1:
                String word = sc.nextLine();
                System.out.println("Is Main: " + isMain(word));
                break;
            case 2:
                String string = sc.nextLine();
                System.out.println("String after removing palindromes: " + removeMains(string));
                break;
            case 3:
                String string2 = sc.nextLine();
                int n = sc.nextInt();
                System.out.println("String after removing nth palindrome: " + removeNthMain(string2, n));
                break;
            case 4:
                String string3 = sc.nextLine();
                System.out.println("Longest Main Substring: " + longestMainSubstring(string3));
                break;
            case 5:
                String string4 = sc.nextLine();
                System.out.println("Can form palindrome: " + canFormMain(string4));
                break;
            default:
                System.out.println("Invalid option");
        }
        sc.close();
    }
}