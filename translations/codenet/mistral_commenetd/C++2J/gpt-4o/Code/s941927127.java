import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable named W to store the input word
        Scanner scanner = new Scanner(System.in);
        String W = scanner.nextLine();

        // Convert the string W to a character array and sort it
        char[] charArray = W.toCharArray();
        Arrays.sort(charArray);
        W = new String(charArray);

        // Loop through the sorted string W
        for (int i = 0; i < W.length() - 1; i++) {
            // Check if the current character and the next character in the string are the same
            if (W.charAt(i) != W.charAt(i + 1)) {
                // If they are not the same, print "No" and return from the main function
                System.out.println("No");
                return;
            }
        }

        // If the loop completes without finding any pair of non-identical characters, print "Yes"
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
