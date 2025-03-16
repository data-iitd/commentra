import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] alpha = new int[26];
        char ch;

        // Initialize the array to zero
        for (int i = 0; i < 26; i++) {
            alpha[i] = 0;
        }

        Scanner scanner = new Scanner(System.in);
        while (true) {
            ch = scanner.next().charAt(0);
            if (ch == EOF) break; // Note: EOF handling in Java is different

            if (Character.isLetter(ch)) {
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++;
                } else {
                    alpha[ch - 'a']++;
                }
            }
        }

        ch = 'a';
        for (int i = 0; i < 26; i++, ch++) {
            System.out.println(ch + " : " + alpha[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
