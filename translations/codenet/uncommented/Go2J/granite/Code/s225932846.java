
import java.util.Scanner;

public class s225932846{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        for (int i = 2; i <= S.length(); i = i + 2) {
            if (S.substring(0, (S.length() - i) / 2).equals(S.substring((S.length() - i) / 2, S.length() - i))) {
                System.out.println(S.length() - i);
                break;
            }
        }
    }
}
