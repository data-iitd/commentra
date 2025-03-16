
import java.util.Scanner;

public class codeforces_99_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();
        String[] parts = l.split("\\.");
        char[] s = parts[0].toCharArray();
        char[] p = parts[1].toCharArray();
        int i = Integer.parseInt(String.valueOf(p[0]));
        if (s[s.length - 1] == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (s[s.length - 1]!= '9' && i < 5) {
            System.out.println(new String(s));
        } else {
            s[s.length - 1] = (char) (s[s.length - 1] + 1);
            System.out.println(new String(s));
        }
    }
}
