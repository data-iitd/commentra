import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define an array containing all the vowels in upper and lower case
        char[] vo = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };

        // Take an input string 'a' from the user
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();

        // Iterate through the string 'a' from the end to the beginning
        for (int i = a.length() - 1; i >= 0; i--) {
            // If the current character is a space or a question mark, skip it and move on to the next character
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {
                continue;
            } else {
                // Check if the current character is a vowel
                boolean isVowel = false;
                for (char vowel : vo) {
                    if (a.charAt(i) == vowel) {
                        isVowel = true;
                        break;
                    }
                }
                // If it is, print "YES" and break out of the loop
                if (isVowel) {
                    System.out.println("YES");
                    break;
                } else {
                    // If it is not, print "NO" and break out of the loop
                    System.out.println("NO");
                    break;
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
