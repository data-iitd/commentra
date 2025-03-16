public class LetterCounter {
    public static void main(String[] args) {
        int[] alpha = new int[26];
        int ch;

        // Initialize the alpha array to zero for all elements
        for (int i = 0; i < 26; i++) {
            alpha[i] = 0;
        }

        // Read characters from the standard input until EOF
        while (true) {
            ch = System.in.read();
            if (ch == -1) break;

            // Check if the character is an alphabetic character
            if (Character.isLetter(ch)) {
                // Increment the corresponding element in alpha based on case
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++;
                } else {
                    alpha[ch - 'a']++;
                }
            }
        }

        // Print the counts of each letter from 'a' to 'z'
        char ch = 'a';
        for (int i = 0; i < 26; i++, ch++) {
            System.out.println(ch + " : " + alpha[i]);
        }
    }
}
