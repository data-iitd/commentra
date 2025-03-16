
import java.util.Scanner;

public class s882312203{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

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

