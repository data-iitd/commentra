
import java.util.Scanner;

public class s695527706{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int count = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            if (s.substring(i, i + 3).equals("ABC")) {
                count++;
            }
        }
        System.out.println(count);
    }
}
// END-OF-CODE