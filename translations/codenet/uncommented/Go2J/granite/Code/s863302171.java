
import java.util.Scanner;

public class s863302171{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.next();

        for (int i = 0; i < 3; i++) {
            if (n.charAt(i) == '7') {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
// END-OF-CODE