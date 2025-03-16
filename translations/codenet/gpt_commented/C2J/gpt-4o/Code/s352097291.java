import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a character array 'c' to store the input string and 'ans' to store the result
        char[] c = new char[11];
        StringBuilder ans = new StringBuilder();
        
        // Read a string input from the user
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        c = input.toCharArray();
        
        // Iterate through each character of the input string
        for (char ch : c) {
            // If the current character is not 'B', append it to the 'ans' string
            if (ch != 'B') {
                ans.append(ch);
            } 
            // If the current character is 'B', remove the last character from 'ans' (if it exists)
            else if (ans.length() > 0) {
                ans.deleteCharAt(ans.length() - 1);
            }
        }
        
        // Print the resulting string after processing the input
        System.out.println(ans.toString());
    }
}

// <END-OF-CODE>
