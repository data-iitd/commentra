
import java.util.Scanner;

public class codeforces_147_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Take input string from user
        StringBuilder res = new StringBuilder();  // Initialize a StringBuilder to store the result
        String[] punctuation = {",", ".", "!", "?"};  // Define an array of punctuation marks

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            if (i >= 1) {  // Check if it's not the first character
                if (s.charAt(i) =='') {  // Check if the current character is a space
                    if (res.charAt(res.length() - 1)!='') {  // Check if the last character in res is not a space
                        res.append(s.charAt(i));  // Append the current space to res
                    } else {
                        continue;  // Skip the current space if the last character is also a space
                    }
                } else {  // If the current character is not a space
                    if (isPunctuation(s.charAt(i))) {  // Check if the current character is a punctuation mark
                        if (res.charAt(res.length() - 1) =='') {  // Check if the last character in res is a space
                            res.deleteCharAt(res.length() - 1);  // Remove the last character (space) from res
                        }
                        res.append(s.charAt(i));  // Append the punctuation mark to res
                        res.append(' ');  // Append a space after the punctuation mark
                    } else {
                        res.append(s.charAt(i));  // Append the character to res if it's not a punctuation mark
                    }
                }
            } else {  // For the first character
                if (s.charAt(i) =='') {  // Check if the first character is a space
                    continue;  // Skip the first space
                }
                if (isPunctuation(s.charAt(i))) {  // Check if the first character is a punctuation mark
                    continue;  // Skip the first punctuation mark
                } else {
                    res.append(s.charAt(i));  // Append the first character to res
                }
            }
        }

        // Print the result
        System.out.println(res.toString());
    }

    public static boolean isPunctuation(char c) {
        for (String p : punctuation) {
            if (p.equals(String.valueOf(c))) {
                return true;
            }
        }
        return false;
    }
}
