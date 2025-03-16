

import java.util.Scanner;

public class atcoder_ABC043_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Take a string input from the user
        StringBuilder myStr = new StringBuilder();  // Initialize a StringBuilder to build the result

        // Iterate over each character in the input string `s`
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '0' || c == '1') {  // Check if the character is '0' or '1'
                myStr.append(c);  // Append the character to `myStr`
            } else if (c == 'B' && myStr.length()!= 0) {  // Check if the character is 'B' and `myStr` is not empty
                myStr.deleteCharAt(myStr.length() - 1);  // Remove the last character from `myStr`
            }
        }

        System.out.println(myStr.toString());  // Print the content of `myStr`
    }
}
