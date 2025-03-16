import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to take input
        String s = scanner.nextLine();  // Take input string from user
        List<Character> res = new ArrayList<>();  // Initialize an empty list to store the result
        char[] punctuation = {',', '.', '!', '?'};  // Define an array of punctuation marks

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);  // Get the current character
            if (i >= 1) {  // Check if it's not the first character
                if (currentChar == ' ') {  // Check if the current character is a space
                    if (res.size() == 0 || res.get(res.size() - 1) != ' ') {  // Check if the last character in res is not a space
                        res.add(currentChar);  // Append the current space to res
                    }
                } else {  // If the current character is not a space
                    boolean isPunctuation = false;
                    for (char p : punctuation) {  // Check if the current character is a punctuation mark
                        if (currentChar == p) {
                            isPunctuation = true;
                            break;
                        }
                    }
                    if (isPunctuation) {  // If it's a punctuation mark
                        if (res.size() > 0 && res.get(res.size() - 1) == ' ') {  // Check if the last character in res is a space
                            res.remove(res.size() - 1);  // Remove the last character (space) from res
                        }
                        res.add(currentChar);  // Append the punctuation mark to res
                        res.add(' ');  // Append a space after the punctuation mark
                    } else {
                        res.add(currentChar);  // Append the character to res if it's not a punctuation mark
                    }
                }
            } else {  // For the first character
                if (currentChar == ' ') {  // Check if the first character is a space
                    continue;  // Skip the first space
                }
                boolean isPunctuation = false;
                for (char p : punctuation) {  // Check if the first character is a punctuation mark
                    if (currentChar == p) {
                        isPunctuation = true;
                        break;
                    }
                }
                if (!isPunctuation) {
                    res.add(currentChar);  // Append the first character to res
                }
            }
        }

        // Join the list res into a string and print it
        StringBuilder result = new StringBuilder();
        for (char c : res) {
            result.append(c);
        }
        System.out.println(result.toString());  // Print the result
    }
}
// <END-OF-CODE>
