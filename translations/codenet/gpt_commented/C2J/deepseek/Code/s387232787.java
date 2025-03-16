public class LetterCounter {
    // Array to hold the count of each letter (a-z)
    static int[] c = new int[26];

    public static void main(String[] args) {
        // Declare a string to hold the input
        char[] str = new char[1200];

        // Read strings from standard input until EOF
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNext()) {
            String input = scanner.next();
            input.getChars(0, input.length(), str, 0);

            // Iterate through each character in the string
            for (char p : str) {
                // Check if the character is a lowercase letter
                if ('a' <= p && p <= 'z') {
                    // Increment the count for the corresponding letter
                    c[p - 'a']++;
                } 
                // Check if the character is an uppercase letter
                else if ('A' <= p && p <= 'Z') {
                    // Increment the count for the corresponding letter (converted to lowercase)
                    c[p - 'A']++;
                }
            }
        }

        // Print the count of each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char)('a' + i) + " : " + c[i]); 
        }
    }
}
