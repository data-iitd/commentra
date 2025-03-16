import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty list to store the result
        List<Character> res = new ArrayList<>();

        // Define a list of punctuation marks to check against
        char[] punctuation = {',', '.', '!', '?'};

        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            // Check if the current index is greater than or equal to 1
            if (i >= 1) {
                // If the current character is a space
                if (currentChar == ' ') {
                    // Only append a space if the last element in res is not a space
                    if (res.isEmpty() || res.get(res.size() - 1) != ' ') {
                        res.add(' ');
                    }
                } else {
                    // If the current character is a punctuation mark
                    boolean isPunctuation = false;
                    for (char p : punctuation) {
                        if (currentChar == p) {
                            isPunctuation = true;
                            break;
                        }
                    }
                    if (isPunctuation) {
                        // If the last element in res is a space, remove it
                        if (!res.isEmpty() && res.get(res.size() - 1) == ' ') {
                            res.remove(res.size() - 1);
                        }
                        // Append the punctuation mark to the result
                        res.add(currentChar);
                        // Append a space after the punctuation
                        res.add(' ');
                    } else {
                        // If the current character is not punctuation, append it to the result
                        res.add(currentChar);
                    }
                }
            } else {
                // For the first character, handle it separately
                if (currentChar != ' ' && !isPunctuation(currentChar, punctuation)) {
                    // Append the first character to the result if it's not a space or punctuation
                    res.add(currentChar);
                }
            }
        }

        // Join the list into a single string and print the result
        StringBuilder result = new StringBuilder();
        for (char c : res) {
            result.append(c);
        }
        System.out.print(result.toString());
    }

    private static boolean isPunctuation(char c, char[] punctuation) {
        for (char p : punctuation) {
            if (c == p) {
                return true;
            }
        }
        return false;
    }
}
// <END-OF-CODE>
