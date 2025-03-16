
import java.util.Scanner;

public class s476941540{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] alpha = new int[26];
        char ch;

        for (int i = 0; i < 26; i++) alpha[i] = 0;

        while (scanner.hasNext()) {
            ch = scanner.next().charAt(0);
            if (Character.isLetter(ch)) {
                if (Character.isUpperCase(ch)) alpha[ch - 65]++;
                else alpha[ch - 97]++;
            }
        }

        ch = 'a';
        for (int i = 0; i < 26; i++, ch++) {
            System.out.printf("%c : %d\n", ch, alpha[i]);
        }
    }
}
