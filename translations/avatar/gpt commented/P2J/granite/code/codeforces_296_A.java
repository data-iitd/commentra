
import java.util.Scanner;

public class codeforces_296_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] m = scanner.next().split(" ");
        boolean possible = true;
        for (String i : m) {
            if (m.length / 2 + 1 <= m.length) {
                possible = false;
                break;
            }
        }
        System.out.println(possible? "YES" : "NO");
    }
}
