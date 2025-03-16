
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        char[] vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {
                continue;
            } else {
                for (char c : vo) {
                    if (a.charAt(i) == c) {
                        System.out.println("YES");
                        break;
                    }
                }
                System.out.println("NO");
                break;
            }
        }
    }
}

