import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.next();
        char c = 'a';

        for (int j = 0; j < 26; j++) {
            boolean found = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println(c);
                return;
            }
            c++;
        }

        System.out.println("None");
        scanner.close();
    }
}

// <END-OF-CODE>
