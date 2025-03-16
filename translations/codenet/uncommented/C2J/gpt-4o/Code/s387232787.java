import java.util.Scanner;

public class LetterCount {
    public static void main(String[] args) {
        int[] c = new int[26];
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNext()) {
            String str = scanner.next();
            for (char p : str.toCharArray()) {
                if ('a' <= p && p <= 'z') {
                    c[p - 'a']++;
                } else if ('A' <= p && p <= 'Z') {
                    c[p - 'A']++;
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + c[i]);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
