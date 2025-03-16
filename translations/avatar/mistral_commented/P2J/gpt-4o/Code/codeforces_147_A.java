import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take user input as a string 's'
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty list 'res' to store the final result
        List<String> res = new ArrayList<>();

        // Define a list 'punctuation' containing all the punctuation marks
        char[] punctuation = {',', '.', '!', '?'};

        // Iterate through each character 'i' in the string 's'
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            // If current character is a space and previous character is not empty,
            // append the space to the result list
            if (i >= 1) {
                if (currentChar == ' ') {
                    if (!res.isEmpty() && !res.get(res.size() - 1).equals(" ")) {
                        // Append space to the result list
                        res.add(" ");
                    }
                }
            }

            // If current character is not a space and is a punctuation mark,
            // check if the previous character is empty, if yes then pop the last character from the result list
            // and append the current punctuation mark along with an empty string
            if (isPunctuation(currentChar, punctuation)) {
                if (!res.isEmpty() && res.get(res.size() - 1).equals(" ")) {
                    res.remove(res.size() - 1); // Remove the last space
                    res.add(String.valueOf(currentChar));
                    res.add(" "); // Add an empty string (space)
                } else {
                    res.add(String.valueOf(currentChar));
                }
            } else if (currentChar != ' ') {
                // If current character is not a space and is not a punctuation mark,
                // simply append it to the result list
                res.add(String.valueOf(currentChar));
            }
        }

        // Join all the elements of the result list and print the final string
        StringBuilder finalString = new StringBuilder();
        for (String str : res) {
            finalString.append(str);
        }
        System.out.println(finalString.toString());

        scanner.close();
    }

    // Helper method to check if a character is a punctuation mark
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
