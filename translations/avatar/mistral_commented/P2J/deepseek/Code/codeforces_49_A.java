public class Main {
    public static void main(String[] args) {
        // Define a list containing all the vowels in upper and lower case
        char[] vo = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };

        // Take an input string 'a' from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String a = scanner.nextLine();

        // Iterate through the string 'a' from the end to the beginning
        for (int i = a.length() - 1; i >= 0; i--) {
            // If the current character is a space or a question mark, skip it and move on to the next character
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {
                continue;
            }
            // If the current character is not a space or a question mark, check if it is a vowel or not
            else {
                // Check if the current character is a vowel
                boolean isVowel = false;
                for (char c : vo) {
                    if (a.charAt(i) == c) {
                        isVowel = true;
                        break;
                    }
                }
                // If it is, print "YES" and break out of the loop
                if (isVowel) {
                    System.out.println("YES");
                    break;
                }
                // If it is not, print "NO" and break out of the loop
                else {
                    System.out.println("NO");
                    break;
                }
            }
        }
    }
}
