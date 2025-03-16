
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i < s.length(); i++) {
                if ((i!= j) && (s.charAt(i) == s.charAt(j))) {
                    System.out.println("no");
                    return;
                }
            }
        }

        System.out.println("yes");
    }
}

