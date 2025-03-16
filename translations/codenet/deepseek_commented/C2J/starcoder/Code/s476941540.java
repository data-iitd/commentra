import java.util.*;

public class CountLetters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] alpha = new int[26];
        char ch;

        // Initialize the alpha array to zero for all elements
        for(int i = 0; i < 26; i++) alpha[i] = 0;

        // Read characters from the standard input until EOF
        while(true){
            ch = sc.next().charAt(0);
            if(ch == 'E') break;

            // Check if the character is an alphabetic character
            if(Character.isLetter(ch)){
                // Increment the corresponding element in alpha based on case
                if(Character.isUpperCase(ch)) alpha[ch - 65]++;
                else alpha[ch - 97]++;
            }
        }

        // Print the counts of each letter from 'a' to 'z'
        ch = 'a';
        for(int i = 0; i < 26; i++, ch++){
            System.out.println(ch + " : " + alpha[i]);
        }
    }
}
