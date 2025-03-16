
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        char c = 'a';

        for (int j = 0; j < 26; j++) {
            boolean found = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true;
                    break;
                }
            }
            if (found == false) {
                System.out.println(c);
                return;
            }
            c++;
        }

        System.out.println("None");

    }
}

